#include<bits/stdc++.h>
using namespace std;

int n,a,p;
long long ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        int t=min(a/2,p);
        p-=t;
        ans+=t;
        a-=t*2;
        ans+=a/3;
        a%=3;
        p+=a;
    }
    cout<<ans;

    return 0;
}