#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll gcd(ll a,ll b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

inline ll lcm(const ll &a,const ll &b){
    return a/gcd(a,b)*b;
}

ll m,d,w,k,b,n,ans;

void mian(){
    cin>>m>>d>>w;
    b=min(m,d)-1;
    k=w/gcd(d-1,w);
    n=b/k;
    ans=(b+1)*n-(1+n)*n/2*k;
    cout<<ans<<endl;
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