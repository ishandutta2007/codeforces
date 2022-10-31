#include <bits/stdc++.h>
using namespace std;
const long long inf=1e9;
long long h[1000001];
long long x,n,m,qq,y;
long long a[1000001];
long long q[1000001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        h[i]=inf;
    h[1]=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>x;
            long long z=i*m-m+j;
            a[z]=x;
            if (z<=m) continue;
            q[z]=q[z-m];
            if (a[z]<a[z-m]) q[z]=i;
            h[i]=min(h[i],q[z]);
        }
    }
    cin>>qq;
    for (int i=1;i<=qq;++i){
        cin>>x>>y;
        if (h[y]>x) cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
}