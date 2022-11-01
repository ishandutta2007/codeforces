#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(ll a,ll b,ll x){
    if(a<b)swap(a,b);
    if(!b)return false;
    if(a%b==x%b&&a>=x)return true;
    return f(b,a%b,x);
}

void mian(){
    ll a,b,x;
    cin>>a>>b>>x;
    cout<<(f(a,b,x)?"YES\n":"NO\n");
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