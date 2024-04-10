#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=200005;
int a[N],ans[N],T,K,G,n,cnt;
set<int>::iterator it;
map<int,int> cur;
vi t[N],id[N];
set<int> s;

inline int exgcd(int a,int b,int &x,int &y){
	if(!b)return x=1,y=0,a;
	int t=exgcd(b,a%b,y,x);
	return y-=a/b*x,t;
}
inline int inv(int a,int mod){
	int x,y,t=exgcd(a,-mod,x,y);
	return (t*x%mod+mod)%mod;
}

int main(){
	scanf("%d%d",&T,&n);
	int last=0;
	s.insert(a[0]=0);
	scanf("%d",&K);
	rep(i,1,n-1){
		scanf("%d",&a[i]);
		last=a[i]=(last+a[i])%T;
		if(s.find(a[i])!=s.end())a[i]=-1;
		else s.insert(a[i]);
	}
	K=(K+last)%T;
	G=__gcd(T,K),T/=G,K/=G;
	if(!K){
		REP(i,n)putchar('0'+(a[i]!=-1)),putchar(' ');
		return 0;
	}
	REP(i,n)if(a[i]!=-1){
		if(!cur[a[i]%G])
			cur[a[i]%G]=++cnt;
		int k=cur[a[i]%G];
		t[k].pb(a[i]/G);
		id[k].pb(i);
	}
	rep(k,1,cnt){
		s.clear();
		for(auto &x:t[k]){
			x=1ll*x*inv(K,T)%T;
			s.insert(x);
		}
		REP(i,t[k].size()){
			it=s.find(t[k][i]);
			if(++it==s.end())it=s.begin();
			ans[id[k][i]]=(*it+T-t[k][i])%T;
			if(!ans[id[k][i]])ans[id[k][i]]=T;
		}
	}
	REP(i,n)printf("%d ",ans[i]);
	return 0;
}