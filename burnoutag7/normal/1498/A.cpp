#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int dsum(ll a){
    int res=0;
    while(a){
        res+=a%10;
        a/=10;
    }
    return res;
}

int gs(ll a){
    return gcd(a,dsum(a));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        while(gs(n)==1)n++;
        cout<<n<<'\n';
    }

    return 0;
}