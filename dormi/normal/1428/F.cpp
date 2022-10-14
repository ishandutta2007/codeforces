#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
pll st[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    cin>>a;
    ll end=n;
    ll ans=0;
    ll sum=0;
    int l=MAXN,r=MAXN-1;
    st[--l]={INT_MAX,n};
    for(int i=n-1;i>=0;i--){
        if(a[i]=='0'){
            if(end!=i+1)l++;
            for(int j=end-1;j>=i+1;j--){
                st[--l]={j-i,j};
            }
            end=i;
        }
        else{
            sum+=(end-i)*(st[l].second-end+1);
            while(l<=r&&st[l].first<=end-i){
                sum+=(end-i-st[l].first)*(st[l+1].second-st[l].second);
                l++;
            }
            st[--l]={end-i,end};
        }
        ans+=sum;
    }
    printf("%lli\n",ans);
    return 0;
}