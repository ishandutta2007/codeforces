#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
pll arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli mihealth=LLONG_MAX;
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        lli ans=0;
        for(int i=0;i<n;i++){
            ans+=max((lli)0,arr[i].first-arr[((i-1)+n)%n].second);
            mihealth=min(mihealth,min(arr[i].first,arr[((i-1)+n)%n].second));
        }
        printf("%lli\n",ans+mihealth);
    }
    return 0;
}