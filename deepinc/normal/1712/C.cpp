#include<bits/stdc++.h>
using namespace std;
int n,k,a[133333],f[133333],c[133333];
int main(){
    int t; cin>>t; while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",a+i),f[a[i]]=i;
        int p;
        for(p=n-1;p&&a[p]<=a[p+1];--p); p++;
        for(int i=1;i<p;++i) p=max(p,f[a[i]]), c[a[i]]=1;
        int w=0;
        for(int i=1;i<=n;++i) w+=c[i],c[i]=0;
        cout<<w<<endl;
    }
}