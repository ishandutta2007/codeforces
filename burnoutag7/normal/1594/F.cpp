#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    ll s,n,k;
    cin>>s>>n>>k;
    cout<<(k>s||n/k*2*k+n%k<=s&&k!=s?"NO\n":"YES\n");
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