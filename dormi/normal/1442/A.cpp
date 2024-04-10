#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e4+1;
ll arr[MAXN];
ll sufmin[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll subbed=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sufmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            sufmin[i]=min(arr[i],sufmin[i+1]);
        }
        bool work=true;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                subbed+=arr[i+1]-arr[i];
                if(subbed>sufmin[i+1]){
                    work=false;
                }
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}