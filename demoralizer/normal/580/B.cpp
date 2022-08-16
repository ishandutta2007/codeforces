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
    ll n,d;
    cin>>n>>d;
    pair<ll,ll> p[n];
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        p[i]={a,b};
    }
    sort(p,p+n);
    ll i=0,j=0,s=0,m=0;
    while(j<n){
        if(p[i].fr+d>p[j].fr){
            s+=p[j].sc;
            j++;
        }
        else{
            s-=p[i].sc;
            i++;
        }
        m=max(s,m);
    }
    cout<<m;
}