#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n%2){
        if(n*n/2>0)printf("%lli %lli\n",n*n/2,n*n/2+1);
        else printf("-1\n");
    }
    else{
        if((n*n/2)/2-1>0)printf("%lli %lli\n",(n*n/2)/2-1,(n*n/2)/2+1);
        else printf("-1\n");
    }
    return 0;
}