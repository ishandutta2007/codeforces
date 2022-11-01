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

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

void mian(){
    ll n,k;
    cin>>n>>k;
    if(n==k){
        for(int i=1;i<k;i++)cout<<"1 ";
        cout<<"1\n";
    }else if(n==k+1){
        for(int i=1;i<k;i++)cout<<"1 ";
        cout<<"2\n";
    }else{
        n-=k;
        ll a=n/2;
        while(lcm(a+1,n-a*2+1)>(n+k)/2)a--;
        cout<<a+1<<' '<<a+1<<' '<<n-a*2+1;
        for(int i=4;i<=k;i++)cout<<" 1";
        cout<<'\n';
    }
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