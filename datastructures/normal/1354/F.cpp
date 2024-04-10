#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define inf 1e15+7
using namespace std;
struct node{
    int a,b,id;
}a[1005];
inline bool cmp(node a,node b){
    return a.b<b.b;
}
int t,n,k,f[1005][1005],c[1005][1005],w[1005];
signed main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        int sumb=0;
        for (int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b;
            a[i].id=i;
            sumb+=a[i].b;
        }
        sort(a+1,a+1+n,cmp);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=k;j++)
                f[i][j]=-inf;
        f[0][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=k&&j<=i;j++){
                if (f[i-1][j]>f[i][j]){
                    f[i][j]=f[i-1][j];
                    c[i][j]=0;
                }
                if (j&&f[i-1][j-1]+a[i].a-a[i].b*(k-j)>=f[i][j]){
                    f[i][j]=f[i-1][j-1]+a[i].a-a[i].b*(k-j);
                    c[i][j]=1;
                }
            }
        int now=k;
        for (int i=n;i>=1;i--){
            if (c[i][now]==1){
                w[now]=i;
                now--;
            }
        }
        cout<<(n-k)*2+k<<endl;
        for (int i=1;i<k;i++)cout<<a[w[i]].id<<' ';
        for (int i=1;i<=n;i++){
            int f=0;
            for (int j=1;j<=k;j++)
                if (i==w[j])f=1;
            if (f==0)cout<<a[i].id<<' '<<-a[i].id<<' ';
        }
        cout<<a[w[k]].id<<endl;
    }
    return 0;
}