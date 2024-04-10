#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
mt19937 rnd((long int)(new char));

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=85;
int w[N][N],col[N],n,K;
ll f[2][N],ans=1e18;

int main(){
	read(n),read(K);
	rep(i,1,n) rep(j,1,n) read(w[i][j]);
	for(;clock()<2.5*CLOCKS_PER_SEC;){
		rep(i,2,n) col[i]=(rnd()%2+2)%2;
		memset(f[0],0x3f,sizeof f[0]);
		f[0][1]=0;
		REP(k,K){
			int p=k&1,q=1-p;
			memset(f[q],0x3f,sizeof f[q]);
			rep(i,1,n) if(col[i]==p)
				rep(j,1,n) if(col[j]==q)
					f[q][j]=min(f[q][j],f[p][i]+w[i][j]);
		}
		ans=min(ans,f[0][1]);
	}
	cout<<ans<<endl;
	return 0;
}