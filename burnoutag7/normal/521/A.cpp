#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,a[4];
char s[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='A')a[0]++;
        if(s[i]=='C')a[1]++;
        if(s[i]=='G')a[2]++;
        if(s[i]=='T')a[3]++;
    }
    sort(a,a+4);
    reverse(a,a+4);
    int m=0;
    while(m<3&&a[m+1]==a[0])m++;
    cout<<qpow(m+1,n)<<endl;

    return 0;
}