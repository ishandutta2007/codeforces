#include<bits/stdc++.h>

using namespace std;

const int maxn=10005;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    int lp=0;
    while(lp!=n){
        int mx=lp+1;
        for(int i=lp+1;i<=mx;i++){
            mx=max(mx,a[i]);
        }
        lp=mx;
        ans++;
    }
    cout<<ans;
    return 0;
}