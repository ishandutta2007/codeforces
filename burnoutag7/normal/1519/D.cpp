#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll sum,a[5005],b[5005],ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sum+=a[i]*b[i];
    }
    ans=sum;
    for(int i=1;i<=n;i++){
        ll cur=sum;
        for(int j=1;i-j>=1&&i+j<=n;j++){
            cur+=-a[i-j]*b[i-j]-a[i+j]*b[i+j]+a[i-j]*b[i+j]+a[i+j]*b[i-j];
            ans=max(ans,cur);
        }
    }
    for(int i=1;i<=n;i++){
        ll cur=sum;
        for(int j=1;i-j+1>=1&&i+j<=n;j++){
            cur+=-a[i-j+1]*b[i-j+1]-a[i+j]*b[i+j]+a[i-j+1]*b[i+j]+a[i+j]*b[i-j+1];
            ans=max(ans,cur);
        }
    }
    cout<<ans;

    return 0;
}