#include <bits/stdc++.h>
using namespace std;

int n,l=1,posmax=1,posmin=1;
int mx,mn,ans;
int a[100005];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    mx=a[1]; mn=a[1]; ans=1;
    for (int i=2;i<=n;++i){
        if (abs(a[i]-a[i-1])>1){
            mx=a[i];
            l=i;
            mn=a[i];
            posmax=i;
            posmin=i;
        } else {
        if (a[i]==mx) posmax=i;
        if (a[i]==mn) posmin=i;
        if (a[i]>mx){
            if (mn!=mx)
            l=posmin+1;
            posmin=posmax;
            mn=mx;
            mx=a[i];
            posmax=i;
        } else
        if (a[i]<mn){
            if (mn!=mx)
            l=posmax+1;
            posmax=posmin;
            mx=mn;
            mn=a[i];
            posmin=i;
        }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}