#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,k;
    cin>>n>>k;
    ll r;
    for(int i=k-1;i>=1;i--){
        if(n%i==0){r=i;break;}
    }
    ll p=n/r;
    cout<<(p*k+r);
}