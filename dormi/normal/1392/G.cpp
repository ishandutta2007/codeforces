#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int correspond[21];
int leftmask[1<<20],rightmask[1<<20];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    string s,ideal;
    cin>>s>>ideal;
    int onebits=count(s.begin(),s.end(),'1')+count(ideal.begin(),ideal.end(),'1');
    int a,b;
    iota(correspond,correspond+k,0);
    for(int i=0;i<(1<<k);i++)leftmask[i]=n,rightmask[i]=-2;
    int leftval=0,rightval=0;
    for(int j=0;j<k;j++){
        if(s[j]=='1')leftval+=(1<<correspond[j]);
        if(ideal[j]=='1')rightval+=(1<<correspond[j]);
    }
    leftmask[leftval]=min(leftmask[leftval],-1);
    rightmask[rightval]=max(rightmask[rightval],-1);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        swap(correspond[a-1],correspond[b-1]);
        leftval=0,rightval=0;
        for(int j=0;j<k;j++){
            if(s[j]=='1')leftval+=(1<<correspond[j]);
            if(ideal[j]=='1')rightval+=(1<<correspond[j]);
        }
        leftmask[leftval]=min(leftmask[leftval],i);
        rightmask[rightval]=max(rightmask[rightval],i);
    }
    int ans=-1;
    pii loc={-1,-1};
    for(int i=(1<<k)-1;i>=0;i--){
        if(leftmask[i]+m<=rightmask[i]&&2*__builtin_popcount(i)+k-onebits>ans){
            ans=2*__builtin_popcount(i)+k-onebits;
            loc={leftmask[i]+1,rightmask[i]};
        }
        for(int j=0;j<k;j++){
            //if(i&(1<<j)) {
                leftmask[i ^ (1 << j)] = min(leftmask[i ^ (1 << j)], leftmask[i]);
                rightmask[i ^ (1 << j)] = max(rightmask[i ^ (1 << j)], rightmask[i]);
          //  }
        }
    }
    printf("%d\n%d %d\n",ans,loc.first+1,loc.second+1);
    return 0;
}