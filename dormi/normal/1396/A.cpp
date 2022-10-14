#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
ll arr[MAXN];
ll am[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printf("1 1\n");
    printf("%lli\n",-arr[0]);
    if(n==1){
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
        return 0;
    }
    if(n==2){
        printf("2 2\n");
        printf("%lli\n",-arr[1]);
        printf("1 1\n");
        printf("0\n");
        return 0;
    }
    arr[0]=0;
    printf("2 %d\n",n);
    ll len=n-1;
    assert(__gcd(len,ll(n))==ll(1));
    for(ll j=0;j<n;j++){
        am[(len*j)%ll(n)]=len*j;
    }
    for(ll j=0;j<n;j++)assert(am[j]%ll(n)==j);
    for(int i=1;i<n;i++){
        ll mod=((arr[i]%ll(n))+ll(n))%ll(n);
        printf("%lli ",-am[mod]);
        arr[i]-=am[mod];
    }
    printf("\n");
    printf("1 %d\n",n);
    for(int i=0;i<n;i++)printf("%lli ",-arr[i]);
    printf("\n");
    return 0;
}