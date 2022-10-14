#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1,MINV=-1e6;
int arr[501][501];
int val[MAXN];
pair<int,pii> locs[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,n;
    cin>>r>>n;
    int x,y;
    for(int i=1;i<=r;i++)for(int j=1;j<=r;j++)arr[i][j]=MINV;
    for(int i=1;i<=n;i++)val[i]=MINV;
    int t;
    locs[0]={0,{1,1}};
    int left=0;
    for(int i=1;i<=n;i++){
        cin>>t>>x>>y;
        locs[i]={t,{x,y}};
        while(t-locs[left].first>=1000){
            for(int j=1;j<=r;j++){
                arr[j][locs[left].second.second]=max(arr[j][locs[left].second.second],val[left]);
            }
            left++;
        }
        for(int j=left;j<i;j++){
            if(locs[j].first+abs(locs[j].second.first-x)+abs(locs[j].second.second-y)<=t){
                val[i]=max(val[i],val[j]+1);
            }
        }
        for(int j=1;j<=r;j++){
            val[i]=max(val[i],arr[x][j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,val[i]);
    }
    printf("%d\n",ans);
    return 0;
}