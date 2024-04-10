#include<bits/stdc++.h>
using namespace std;

int n,a[100005],m,b[100005],ans,f[100005],p[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=b[m])b[++m]=a[i];
    }
    swap(a,b);
    swap(n,m);
    for(int i=1;i<=n;i++){
        if(p[a[i]]){
            f[i]=min(f[p[a[i]]+1]+i-p[a[i]]-2,f[i-1]+1);
        }else{
            f[i]=f[i-1]+1;
        }
        p[a[i]]=i;
    }
    cout<<f[n]<<endl;

    return 0;
}