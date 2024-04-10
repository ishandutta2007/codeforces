#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int diff=y-x;
        int best=INT_MAX;
        vector<int> arr;
        for(int i=n-1;i>=1;i--){
            if(diff%i==0){
                int gap=diff/i;
                int needed=n-(i+1);
                int lowerfit=(x-1)/gap;
                if(y+max(0,needed-lowerfit)*gap<best){
                    best=y+max(0,needed-lowerfit)*gap;
                    arr=vector<int>();
                    for(int j=0;j<n;j++){
                        arr.push_back(best-j*gap);
                    }
                }
            }
        }
        for(auto x:arr)printf("%d ",x);
        printf("\n");
    }
    return 0;
}