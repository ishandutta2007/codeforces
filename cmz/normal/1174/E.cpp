#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100,mod=1000000007;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
    char ch=getchar();ll x=0,f=0;
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,lt,f[maxn][21][2];
inline int cnt(int x){return n/x;}
int main(){
    n=read();
    lt=log2(n);
    f[1][lt][0]=1;
    if((1<<(lt-1))*3<=n) f[1][lt-1][1]=1;
    FOR(i,2,n) FOR(j,0,lt){
        f[i][j][0]=(1ll*f[i-1][j][0]*(cnt(1<<j)-(i-1))+1ll*f[i-1][j+1][0]*(cnt(1<<j)-cnt(1<<(j+1)))+1ll*f[i-1][j][1]*(cnt(1<<j)-cnt((1<<j)*3)))%mod;
        f[i][j][1]=(1ll*f[i-1][j][1]*(cnt((1<<j)*3)-(i-1))+1ll*f[i-1][j+1][1]*(cnt((1<<j)*3)-cnt((1<<(j+1))*3)))%mod;
    }
    printf("%d\n",f[n][0][0]);
}