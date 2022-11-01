#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll p,a,b,c;
    cin>>p>>a>>b>>c;
    cout<<min((a-p%a)%a,min((b-p%b)%b,(c-p%c)%c))<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)solve();

    return 0;
}