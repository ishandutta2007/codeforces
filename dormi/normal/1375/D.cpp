#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1001;
int arr[MAXN];
bool cnt[MAXN];
int n;
bool good(){
    for(int i=0;i<n;i++){
        if(arr[i]!=i)return false;
    }
    return true;
}
int getmex(){
    for(int i=0;i<n;i++)cnt[i]=false;
    for(int i=0;i<n;i++){
        if(arr[i]<n)cnt[arr[i]]=true;
    }
    for(int i=0;i<n;i++)if(!cnt[i])return i;
    return n;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> inds;
        while(!good()){
            int te=getmex();
            assert(sz(inds)<=2*n);
            if(te==n){
                bool ree=false;
                for(int i=0;i<n;i++){
                    if(arr[i]!=i){
                        ree=true;
                        arr[i]=te;
                        inds.push_back(i+1);
                        break;
                    }
                }
                assert(ree);
            }
            else{
                inds.push_back(te+1);
                arr[te]=te;
            }
        }
        assert(sz(inds)<=2*n);
        printf("%d\n",sz(inds));
        for(int x:inds)printf("%d ",x);
        printf("\n");
    }
    return 0;
}