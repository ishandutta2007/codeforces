#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+2;
int arr[MN];
int cnt[MN];
int cnt2[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> vals;
        for(int i=0;i<=n+1;i++){
            vals.insert(i);
        }
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            cnt[arr[i]]++;
            vals.erase(arr[i]);
        }
        int index=1;
        vector<int> barr;
        while(index<=n){
            int best=*vals.begin();
            barr.push_back(best);
            int newindex=index+1;
            int mex=(arr[index]==0?1:0);
            cnt2[arr[index]]++;
            while(mex<best){
                cnt2[arr[newindex]]++;
                while(cnt2[mex]>0){
                    mex++;
                }
                newindex++;
            }
            for(int i=index;i<newindex;i++){
                cnt2[arr[i]]--;
                cnt[arr[i]]--;
                if(cnt[arr[i]]==0)vals.insert(arr[i]);
            }
            index=newindex;
        }
        printf("%d\n",sz(barr));
        for(int i=0;i<sz(barr);i++){
            printf("%d%c",barr[i]," \n"[i==sz(barr)-1]);
        }
    }
    return 0;
}