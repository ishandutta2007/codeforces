#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define qwq(x) cerr<<"# "<<#x<<" = "<<x<<endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
using namespace std;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005;
int mark[N],vis[N],cur[N],n,m,cnt,a,b;
map<pii,int> appear;
bits s[N],nei[N];
vector<pii> ans;
vi e[N];

int main(){
	read(n);
	if(n==2){
		puts("1 2");
		return 0;
	}
	rep(i,1,n){
		read(m);
		rep(j,1,m){
			read(a);
			s[i].set(a);
		}
	}
	rep(i,1,n)rep(j,i+1,n){
		bits t=s[i]&s[j];
		if(t.count()==2){
			int a=t._Find_first();
			int b=t._Find_next(a);
			if(appear[mp(a,b)])continue;
			appear[mp(a,b)]=1;
			appear[mp(b,a)]=1;
			mark[a]=1,mark[b]=1,cnt++;
			nei[a].set(a),nei[b].set(b);
			nei[a].set(b),nei[b].set(a);
			ans.pb(mp(a,b));
		}
	}
	if(cnt==0){
		rep(i,2,n)printf("1 %d\n",i);
		return 0;
	}
	rep(i,1,n)cur[i]=i;
	hash<bits> fun;
	sort(cur+1,cur+n+1,[&](int a,int b){
		int A=s[a].count(),B=s[b].count();
		if(A!=B)return A<B;
		return fun(s[a])<fun(s[b]);
	});
	for(int l=1,r;l<=n;l++){
		r=l;
		while(r<n&&s[cur[l]]==s[cur[r+1]])r++;
		int p=cur[l],o=0,cnt=0,t;
		for(int i=s[p]._Find_first();i<s[p].size();i=s[p]._Find_next(i)){
			if(mark[i]&&!vis[i]&&(s[p]&nei[i])==nei[i]
			&&(!o||nei[i].count()>nei[o].count())) o=i;
			if(!mark[i]&&!vis[i])++cnt;
		}
		if(r-l+1!=cnt)continue;
		vis[o]=1;
		for(int i=s[p]._Find_first();i<s[p].size();i=s[p]._Find_next(i))
			if(!mark[i]&&!vis[i]){
				ans.pb(mp(o,i));
				vis[i]=1;
			}
		l=r;
	}
	for(auto x:ans)
		printf("%d %d\n",x.fi,x.se);
	return 0;
}