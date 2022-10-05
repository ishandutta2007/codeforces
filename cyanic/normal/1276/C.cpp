#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005;
int n,a,sum,mx,r,c,cur,ans[N];
map<int,int> cnt;
vi owo[N],mat[N];
pii ans2[N];

int main(){
	read(n);
	rep(i,1,n){
		read(a);
		++cnt[a];
		owo[cnt[a]].pb(a);
	}
	for(int i=1;i<=n;i++){
		sum+=owo[i].size();
		int t=sum/i;
		if(t>=i&&t*i>mx){
			mx=t*i,r=i,c=t;
		}
	}
	cnt.clear();
	per(i,r,1){
		while(owo[i].size()&&cur<mx){
			ans[++cur]=owo[i].back();
			++cnt[ans[cur]];
			owo[i].pop_back();
		}
	}
	rep(i,1,mx) ans2[i]=mp(-cnt[ans[i]],ans[i]);
	sort(ans2+1,ans2+mx+1);
	rep(i,1,r) mat[i].resize(c+2);
	cur=0;
	rep(i,1,c){
		int x=1,y=i;
		rep(j,1,r){
			mat[x][y]=ans2[++cur].se;
			++x,++y;
			if(y>c) y-=c;
		}
	}
	printf("%d\n%d %d\n",r*c,r,c);
	rep(i,1,r){
		rep(j,1,c) printf("%d ",mat[i][j]);
		puts("");
	}
	return 0;
}