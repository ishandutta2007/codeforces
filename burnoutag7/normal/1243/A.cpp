#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    while(k--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ans=0;
        for(int i=n;--i>=0;){
            ans=max(ans,min(a[i],n-i));
        }
        cout<<ans<<endl;
    }

    return 0;
}