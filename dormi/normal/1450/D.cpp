#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+2;
int good[MAXN],arr[MAXN];
map<int,vector<int>> locs;
int thingy[MAXN],thingy2[MAXN];
int deq[MAXN];
int l,r;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        locs=map<int,vector<int>>();
        arr[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            locs[arr[i]].push_back(i);
            thingy[i]=0,thingy2[i]=0;
            good[i]=0;
        }
        for(auto x:locs){
            good[1]--;
            good[x.second.back()-x.second.front()+1]++;
        }
        l=0,r=-1;
        deq[++r]=0;
        for(int i=1;i<=n;i++){
            while(l<=r&&arr[deq[r]]>=arr[i])r--;
            thingy[i]=i-deq[r];
            deq[++r]=i;
        }
        l=0,r=-1;
        deq[++r]=n+1;
        for(int i=n;i>=1;i--){
            while(l<=r&&arr[deq[r]]>=arr[i])r--;
            thingy2[i]=thingy[i]+deq[r]-i;
            thingy[i]=min(thingy[i],deq[r]-i);
            deq[++r]=i;
        }
        for(int i=1;i<=n;i++){
            if(thingy[i]>=2){
                good[2]--;
                good[thingy[i]+1]++;
            }
            int longest=0;
            for(auto x:locs[i]){
                longest=max(longest,thingy2[x]-1);
            }
            good[1]++;
            good[min(n-i+2,longest+1)]--;
        }
        for(int i=1;i<=n;i++){
            good[i]+=good[i-1];
            if(good[i]==n-i+1)printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}