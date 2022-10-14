#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int segcnt=0;
        int left=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                if(i-left-1>0)segcnt++;
                left=i;
            }
        }
        if(n+1-left-1>0)segcnt++;
        printf("%d\n",min(segcnt,2));
    }
    return 0;
}