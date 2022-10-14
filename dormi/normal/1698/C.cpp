#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> pos,neg;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]>0)pos.push_back(arr[i]);
            if(arr[i]<0)neg.push_back(arr[i]);
        }
        if(sz(pos)>2||sz(neg)>2){
            printf("NO\n");
            continue;
        }
        int zeros=n-sz(pos)-sz(neg);
        for(auto x:neg)pos.push_back(x);
        for(int i=0;i<min(3,zeros);i++)pos.push_back(0);
        bool work=true;
        for(int i=0;i<sz(pos);i++){
            for(int j=i+1;j<sz(pos);j++){
                for(int k=j+1;k<sz(pos);k++){
                    bool found=false;
                    for(auto x:pos){
                        if(x==pos[i]+pos[j]+pos[k]){
                            found=true;
                        }
                    }
                    if(!found)work=false;
                }
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}