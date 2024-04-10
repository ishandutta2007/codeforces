#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N],b[N],ans[N];
int main(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    long long mx=0;
    for (int i=1;i<=n;++i){
        long long s=b[i]=a[i];
        for (int j=i-1;j;--j)
            s+=b[j]=min(b[j+1],a[j]);
        for (int j=i+1,l=a[i];j<=n;++j)
            s+=b[j]=min(b[j-1],a[j]);
        if (s>mx){
            mx=s;
            for (int j=1;j<=n;++j) ans[j]=b[j];
        }
    }
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
}