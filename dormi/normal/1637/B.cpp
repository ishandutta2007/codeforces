#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=101;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int zerocnt=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]==0)zerocnt++;
            int te=zerocnt;
            for(int j=1;j<=i;j++){
                ans+=(i-j+1)+te;
                if(arr[j]==0){
                    te--;
                }
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}