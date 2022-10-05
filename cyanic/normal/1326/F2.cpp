#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pc __builtin_popcount
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;

const int N=18;
ll f[1<<N][N],g[N+1][1<<N],h[N+1][1<<N],res[1<<N];
map<vi,ll> ans;
int e[N],n,all;

void fmt(ll *a){
	for(int k=0,d=1;k<n;d<<=1,k++)
		for(int i=0;i<(1<<n);i+=d<<1){
			ll *l=a+i,*r=a+i+d;
			REP(j,d) *(r++)+=*(l++);
		}
}
void ifmt(ll *a){
	for(int k=0,d=1;k<n;d<<=1,k++)
		for(int i=0;i<(1<<n);i+=d<<1){
			ll *l=a+i,*r=a+i+d;
			REP(j,d) *(l++)-=*(r++);
		}
}

void dfs(int d,int mx,int re,vi &v){
	if(!re){
		ll res=0;
		REP(s,1<<n) res+=(pc(s^all)&1?-h[d][s]:h[d][s]);
		ans[v]=res;
		return; 
	}
	rep(i,1,min(mx,re)){
		v.pb(i);
		REP(s,1<<N) h[d+1][s]=h[d][s]*g[i][s];
		dfs(d+1,i,re-i,v);
		v.pop_back();
	}
}

int main(){
	cin>>n; all=(1<<n)-1;
	REP(i,n){
		char s[N+1]; scanf("%s",s);
		REP(j,n) if(s[j]=='1') e[i]|=1<<j;
		f[1<<i][i]=1;
	}
	REP(s,1<<n) REP(i,n) if(f[s][i]){
		REP(j,n) if(!(s>>j&1)&&(e[i]>>j&1))
			f[s|(1<<j)][j]+=f[s][i];
		g[pc(s)][s]+=f[s][i];
	}
	rep(i,0,n) fmt(g[i]);
	REP(s,1<<n) h[0][s]=1;
	vi V; dfs(0,n,n,V),n--;
	REP(s,1<<n){
		vi v;
		for(int p=0,q;p<=n;p++){
			for(q=p;s>>q&1;q++);
			v.pb(q-p+1),p=q;
		}
		sort(v.begin(),v.end(),greater<int>());
		res[s]=ans[v];
	}
	ifmt(res);
	REP(s,1<<n) printf("%lld ",res[s]);
	return 0;
}