#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int n=100;
vi f[n+1][n*(n+1)/2+1],g[n+1];

int main(){
	rep(i,4,n){
		rep(j,1,i) if(j%2==0) g[i].pb(j);
		rep(j,1,i) if(j%2==1) g[i].pb(j);
		if(i&1) swap(g[i][i-2],g[i][i-1]);
	}
	f[1][1]={1},f[2][3]={1,2};
	rep(i,1,n) rep(j,1,i*(i+1)/2){
		if(f[i][j].empty()) continue;
		rep(k,2,n-i+1){
			auto &r=f[i+k-1][j+k*(k+1)/2-1];
			if(!r.empty()) continue;
			r=f[i][j];
			if(r.back()==i) reverse(r.begin(),r.end());
			rep(p,1,k-1) r.pb(i+p);
		}
		rep(k,4,n-i+1){
			auto &r=f[i+k-1][j+k];
			if(!r.empty()) continue;
			for(auto p:g[k]){
				if(p==1) r.insert(r.end(),f[i][j].begin(),f[i][j].end());
				else r.pb(i+p-1);
			}
		}
	}
	int Q; read(Q);
	while(Q--){
		int n,k;
		read(n),read(k);
		if(f[n][k].empty()){
			puts("NO");
			continue;
		}
		puts("YES");
		for(auto x:f[n][k]) printf("%d ",x);
		puts("");
	}

	return 0;
}