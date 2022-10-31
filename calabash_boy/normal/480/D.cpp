#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=500+10;
struct dong{
    int in,out,w,s,v;
    void read(){
        scanf("%d%d%d%d%d",&in,&out,&w,&s,&v);
    }
    friend bool operator <(dong a,dong b){
        return a.out<b.out||a.out==b.out&&a.in>b.in;
    }
} p[maxn];
int dp[maxn][maxn*2],f[maxn*2];
int i,j,k,l,t,w,o,wi,n,m;
int main (){
    scanf("%d%d",&n,&m);
    p[0]=(dong){0,2*maxn,0,m,0};
    fo(i,1,n) p[i].read();
    sort(p,p+n+1);
    fo(i,0,n){
        fo(j,p[i].w,m){
            k=p[i].in;
            t=min(p[i].s,j-p[i].w);
            f[k]=0;
            fo(l,0,i-1) 
                if (p[l].in>=p[i].in){
                    while (k<p[l].out){
                        k++;
                        f[k]=f[k-1];
                    }
                    f[k]=max(f[k],f[p[l].in]+dp[l][t]);
                }
            dp[i][j]=f[k]+p[i].v;
        }
    }
    printf("%d\n",dp[n][m]);
}