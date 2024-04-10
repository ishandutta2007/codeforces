#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int bitcount[20];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        int bi=0;
        while(a){
            if(a%2)bitcount[bi]++;
            bi++;
            a/=2;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll num=0;
        for(int j=19;j>=0;j--){
            if(bitcount[j]){
                num+=(1<<(ll)j);
                bitcount[j]--;
            }
        }
        ans+=num*num;
    }
    printf("%lli\n",ans);
    return 0;
}