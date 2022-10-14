#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3001;
int arr[MAXN];
vector<int> freq[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)freq[i]=vector<int>();
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            freq[arr[i]].push_back(i);
        }
        ll ans=0;
        ll am=0;
        for(int i=1;i+2<n;i++){
            am=0;
            for(int k=i+2;k<n;k++){
                am-=lower_bound(freq[arr[k]].begin(),freq[arr[k]].end(),k-1)-lower_bound(freq[arr[k]].begin(),freq[arr[k]].end(),i+1);
                am+=freq[arr[k-1]].end()-lower_bound(freq[arr[k-1]].begin(),freq[arr[k-1]].end(),k+1);
                if(arr[k]==arr[i])ans+=am;
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}