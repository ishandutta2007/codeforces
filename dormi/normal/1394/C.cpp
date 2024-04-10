#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+1;
pii arr[MAXN];
pii ans;
int n;
int maxsz=0;
bool work(int maxdiff){
    pii mi={0,0},ma={maxsz,maxsz};
    int min0y=INT_MIN;//larger than or equal to this line(y),m=1
    int max0y=INT_MAX;// less than or equal to this line(y),m=1
    for(int i=0;i<n;i++){
        mi.first=max(mi.first,arr[i].first-maxdiff);
        mi.second=max(mi.second,arr[i].second-maxdiff);
        ma.first=min(ma.first,arr[i].first+maxdiff);
        ma.second=min(ma.second,arr[i].second+maxdiff);
        min0y=max(min0y,arr[i].second-maxdiff-arr[i].first);
        max0y=min(max0y,arr[i].second+maxdiff-arr[i].first);
    }
    if(min0y<=max0y&&mi.first<=ma.first&&mi.second<=ma.second){
        int late=mi.second-max0y;
        int lete=ma.second-min0y;
        late=max(late,mi.first);
        lete=min(lete,ma.first);
        int leteloc=min(lete+max0y,ma.second);
        if(late<=lete&&leteloc+lete>0){
            assert(leteloc>=mi.second);
            ans={lete,leteloc};
            return true;
        }
        return false;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        maxsz=max(maxsz,sz(s));
        for(int j=0;j<sz(s);j++){
            if(s[j]=='B')arr[i].first++;
            else arr[i].second++;
        }
    }
    int lo=0,hi=2*maxsz;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(mid))hi=mid;
        else lo=mid+1;
    }
    work(lo);
    printf("%d\n",lo);
    for(int i=0;i<ans.first;i++)printf("B");
    for(int i=0;i<ans.second;i++)printf("N");
    printf("\n");
    return 0;
}