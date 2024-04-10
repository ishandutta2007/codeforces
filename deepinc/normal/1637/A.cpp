#include<bits/stdc++.h>
using namespace std;
int t,n,a[12345],mx[12345],mn[12345];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)mx[i]=max(a[i],mx[i-1]);
        mn[n+1]=1e9+1;
        for(int i=n;i;--i)mn[i]=min(mn[i+1],a[i]);
        for(int i=1;i<n;++i)if(mx[i]>mn[i+1]){puts("YES");goto x;}
        puts("NO"); x:;
    }
}