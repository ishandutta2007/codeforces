#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1e6+5;
int f[N][2],x[N],n;

void rmain(){
	read(n);
	rep(i,1,n){
		read(x[i]);
		f[i][0]=f[i][1]=-N;
	}
	f[1][0]=f[1][1]=1;
	rep(i,2,n){
		REP(a,2) REP(b,2){
			if(x[i-1]+a<x[i]+b){
				f[i][b]=max(f[i][b],f[i-1][a]+1);
			}
			else if(x[i-1]+a==x[i]+b){
				f[i][b]=max(f[i][b],f[i-1][a]);
			}
		}
	}
	int ans=max(f[n][0],f[n][1]);
	printf("%d\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}