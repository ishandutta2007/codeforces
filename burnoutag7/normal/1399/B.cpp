#include<bits/stdc++.h>
using namespace std;

int n,a[55],b[55],ma,mb;
long long ans;

void mian(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ma=*min_element(a,a+n);
    mb=*min_element(b,b+n);
    ans=0;
    for(int i=0;i<n;i++){
        ans+=max(a[i]-ma,b[i]-mb);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}