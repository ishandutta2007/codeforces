#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        lli lo=0;
        lli hi=1e10;
        while(lo!=hi){
            lli mid=(lo+hi)/2;
            if(mid-mid/n>=k)hi=mid;
            else lo=mid+1;
        }
        printf("%lli\n",lo);
    }
    return 0;
}