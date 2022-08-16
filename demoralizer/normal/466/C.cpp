#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,c,z=0,y=0;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(i>0)b[i]+=b[i-1];
    }
    if(b[n-1]%3||n<3){
        cout<<0;
        return 0;
    }
    c=b[n-1]/3;
    for(ll i=0;i<n-1;i++){
        if(b[i]==2*c)y+=z;
        if(b[i]==c)z++;
    }
    cout<<y;
}