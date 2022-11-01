#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[100005];
int f[100005];
int pos,t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }

    for(int i=1;i<=n;i++){
        while(f[i]-f[pos]>t)pos++;
        ans=max(ans,i-pos);
    }

    cout<<ans<<endl;

    return 0;
}