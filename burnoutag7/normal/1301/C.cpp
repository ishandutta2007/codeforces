#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        ll emp=n-m;
        ll szs,szb,s,b;
        s=emp/(m+1);
        szb=emp-(m+1)*s;
        b=s+1;
        szs=m+1-szb;
        cout<<n*(n+1)/2-szb*b*(b+1)/2-szs*s*(s+1)/2<<endl;
    }

    return 0;
}