#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
int arr[MAXN],occ[MAXN];
int loc[2*MAXN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],occ[arr[i]]++;
    int most=max_element(occ,occ+101)-occ;
    int ans=0;
    for(int i=1;i<=100;i++){
        if(i!=most){
            int cur=0;
            fill(loc,loc+2*n+1,-1);
            loc[n]=0;
            for(int j=1;j<=n;j++){
                if(arr[j]==most)cur++;
                else if(arr[j]==i)cur--;
                if(loc[cur+n]!=-1)ans=max(ans,j-loc[cur+n]);
                else loc[cur+n]=j;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}