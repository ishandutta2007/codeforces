#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
int dphalf[MAXN],dptot[MAXN];
vector<int> locs[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> sarr;
        dphalf[n]=0,dptot[n]=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            dphalf[i]=0,dptot[i]=0;
            sarr.push_back(arr[i]);
        }
        sort(sarr.begin(),sarr.end());
        sarr.erase(unique(sarr.begin(),sarr.end()),sarr.end());
        for(int i=1;i<=sz(sarr);i++)locs[i].clear();
        for(int i=0;i<n;i++)locs[(lower_bound(sarr.begin(),sarr.end(),arr[i])-sarr.begin())+1].push_back(i);
        int best=0;
        for(int i=0;i<n;i++){
            int cur=(lower_bound(sarr.begin(),sarr.end(),arr[i])-sarr.begin())+1;
            dphalf[cur]=max({dphalf[cur],dptot[cur-1],(int)(upper_bound(locs[cur-1].begin(),locs[cur-1].end(),i)-locs[cur-1].begin())})+1;
            best=max(best,dphalf[cur]);
            if(locs[cur].back()==i){
                int te=upper_bound(locs[cur-1].begin(),locs[cur-1].end(),*locs[cur].begin())-locs[cur-1].begin();
                dptot[cur]=(te==sz(locs[cur-1])?dptot[cur-1]:te)+sz(locs[cur]);
                best=max(best,dptot[cur]);
            }
        }
        printf("%d\n",n-best);
    }
    return 0;
}