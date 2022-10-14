#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int arr[53];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> ops;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(!is_sorted(arr,arr+n)){
        int loc=n-1;
        while(arr[loc]==loc+1)loc--;
        vector<int> lens;
        if(n-loc-1>0)lens.push_back(n-loc-1);
        int en=loc;
        while(arr[loc-1]==arr[loc]-1)loc--;
        lens.push_back(en-loc+1);
        int fr=loc;
        while(arr[loc]!=arr[en]+1)loc--;
        lens.push_back(fr-loc);
        if(loc)lens.push_back(loc);
        reverse(lens.begin(),lens.end());
        ops.push_back(lens);
        int ind=0;
        vector<vector<int>> torev;
        for(int x:lens){
            vector<int> te;
            while(x--){
                te.push_back(arr[ind]);
                ind++;
            }
            torev.push_back(te);
        }
        reverse(torev.begin(),torev.end());
        ind=0;
        for(auto x:torev){
            for(auto y:x){
                arr[ind++]=y;
            }
        }
    }
    assert(sz(ops)<=n);
    printf("%d\n",sz(ops));
    for(auto x:ops){
        printf("%d ",sz(x));
        for(auto y:x){
            printf("%d ",y);
        }
        printf("\n");
    }
    return 0;
}