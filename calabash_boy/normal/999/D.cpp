#include<bits/stdc++.h>
using namespace std;
const int N = 533333;
long long a[N],b[N],c[N],k,an[N],f[N],an1[N],g[N],g1[N],ans;
int n,m;
struct pint{
    int x,y;
};
bool cmp(pint a,pint b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}
pint d[N];
void input(){
    cin>>n>>m;
    k=n/m;
    for(int i = 1; i <= n; ++i)cin>>a[i];
    for(int i = 1; i <= n; ++i)b[i]=a[i]%m+1;
    for(int i = 1; i <= n; ++i) {
        c[(int)b[i]]++;
        d[i].x=(int)b[i];
        d[i].y=i;
    }
    for(int i = 1; i <= m; ++i)f[i]=f[i-1]+c[i];
    sort(d+1,d+1+n,cmp);
}
int main(){
    input();
    for(int i = 1; i <= m; ++i)c[i]-=k;
    for(int i = 1; i <= m; ++i)
        if(c[i]>0) {
            an[i]+=c[i];
            c[i+1]+=c[i];
            c[i]=0;
        }
    c[1]+=c[m+1];
    for(int i = 1; i <= m; ++i)
        if(c[i]>0) {
            an1[i]+=c[i];
            c[i+1]+=c[i];
            c[i]=0;
        }
    for(int i = 1; i <= m; ++i) {
        g[f[i]+1]--;
        f[i]-=an[i];
        g[f[i]+1]++;
    }
    for(int i = 1; i <= m; ++i)f[i]+=an[m];
    for(int i = 1; i <= m; ++i) {
        g1[f[i]+1]--;
        f[i]-=an1[i];
        g1[(int)f[i]+1]++;
    }
    for(int i = 1; i <= n; ++i)g[i]+=g[i-1];
    for(int i = 1; i <= n; ++i)g1[i]+=g1[i-1];
    for(int i = 1; i <= n; ++i)g[i]+=g1[(int)(i+an[m]-1)%n+1];
    for(int i = 1; i <= n; ++i)a[d[i].y]+=g[i];
    for(int i = 1; i <= n; ++i)ans+=an[i]+an1[i];
    cout<<ans<<endl;
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    return 0;
}