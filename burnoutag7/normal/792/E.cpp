#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[505];

ll test(int x){
    ll res=0;
    for(int i=1;i<=n;i++){
        int c=a[i];
        if(c/x<c%x)return 1e18;
        res+=c%x;
        c-=c%x*(x+1);
        c/=x;
        res+=c/(x+1)*x;
        c%=x+1;
        res+=c;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll ans=1e18;
    for(int i=1;i*i<=1e9;i++)ans=min(ans,test(i));
    for(int i=1;i*i<=a[1];i++){
        ans=min(ans,test(a[1]/i));
        if(a[1]%i==0&&a[1]!=i)ans=min(ans,test(a[1]/i-1));
    }
    cout<<ans;

    return 0;
}