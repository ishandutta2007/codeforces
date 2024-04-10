#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e3+1;
int arr[MAXN];
int ma[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> sarr;
        ma[n]=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ma[i]=0;
            sarr.push_back(arr[i]);
        }
        sort(sarr.begin(),sarr.end());
        sarr.erase(unique(sarr.begin(),sarr.end()),sarr.end());
        int best=0;
        for(int i=0;i<n;i++){
            int cur=(lower_bound(sarr.begin(),sarr.end(),arr[i])-sarr.begin())+1;
            ma[cur]=max(ma[cur],ma[cur-1])+1;
            best=max(best,ma[cur]);
        }
        printf("%d\n",n-best);
    }
    return 0;
}