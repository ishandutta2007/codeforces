#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m,r=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if((i*i+j*j)%m==0)r++;
        }
    }
    ll k=(n/m),
    x=k*k*r;
    ll z=n%m;
    r=0;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=z;j++){
            if((i*i+j*j)%m==0)r++;
        }
    }
    x+=r;
    r=0;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=m;j++){
            if((i*i+j*j)%m==0)r++;
        }
    }
    x+=2*r*k;
    cout<<x;
}