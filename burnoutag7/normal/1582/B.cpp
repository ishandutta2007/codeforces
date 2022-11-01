#include<bits/stdc++.h>
using namespace std;

int n,a[65],cnt;
long long ans;

void mian(){
    cin>>n;
    ans=1;
    cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i]==1;
        ans*=1+!a[i];
    }
    cout<<cnt*ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}