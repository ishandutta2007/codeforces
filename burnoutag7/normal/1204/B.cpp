#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,l,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    ll mn=(1<<l)-1+n-l;
    ll mx=(1ll<<(r-1))*(n-r+1)+(1<<(r-1))-1;
    cout<<mn<<' '<<mx<<endl;

    return 0;
}