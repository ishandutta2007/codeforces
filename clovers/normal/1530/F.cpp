/*
the vast starry sky,
bright for those who chase the light
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int MOD=31607;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=(ll)x*y%MOD;}
int qpow(int x,int y){int ret=1; while(y){if(y&1) Mul(ret,x); Mul(x,x); y>>=1;} return ret;}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c<='9'&&c>='0') x=x*10+c-'0',c=getchar();
    return x*f;
}
#define out(x) cerr<<#x<<'='<<x<<"  "
#define outln(x) cerr<<#x<<'='<<x<<'\n'
#define sz(x) (int)(x.size())
const int N=21;
const int invv=qpow(10000,MOD-2);
int n,p[N][N];
int sum[21][1<<21];
int main(){
	n=read();
	int full=(1<<n)-1;
	for(int i=0;i<n;i++){
		sum[i][0]=1;
		for(int j=0;j<n;j++){
			p[i][j]=mul(read(),invv);
			sum[i][1<<j]=p[i][j];
		}
		for(int S=1;S<=full;S++) sum[i][S]=mul(sum[i][S&(-S)],sum[i][S^(S&(-S))]);
		for(int S=0;S<=full;S++) Sub(sum[i][S],sum[i][full]);
	}
	int ans=0;
	for(int d=0;d<4;d++){
        for(int S=0;S<=full;S++){
            int ret=__builtin_parity(d^S)?1:MOD-1;
			for(int i=0;i<n;i++){
				int now=(S|(d&1)<<i|(d>>1)<<n-i-1);
				Mul(ret,sum[i][now]);
			}
			Add(ans,ret);
        }
    }
	cout<<add(ans,1)<<endl;
	return 0;
}