#include<bits/stdc++.h>
using namespace std;

int n,a[55];

void mian(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    bool f=1;
    for(int i=0;i+1<n;i++)f&=abs(a[i]-a[i+1])<=1;
    cout<<(f?"YES\n":"NO\n");
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