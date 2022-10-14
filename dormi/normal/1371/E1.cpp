#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int canplace[(int)1e5+1];
int monsters[(int)1e5+1];
map<int,int> bads;
int n,p;
bool work(int candy){
    for(int i=1;i<=n;i++){
        if(candy+i-1<monsters[i])return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>p;
    int ma=0;
    for(int i=1;i<=n;i++){
        cin>>monsters[i];
        ma=max(ma,monsters[i]);
    }
    sort(monsters+1,monsters+1+n);
    int lo=0,hi=ma;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(mid))hi=mid;
        else lo=mid+1;
    }
    int st=lo;
    int en=ma;
    for(int i=1;i<=n;i++){
        canplace[max(0,monsters[i]-st)]++;
    }
    int am=0;
    int upperbound=en-lo;
    for(int i=n-1;i>=0;i--){
        for(int k=0;k<canplace[i];k++){
            int te=(n-i-am)%p;
            int bafmodloc=(p-te)%p;
            int finalloc=i;
            if(finalloc%p==bafmodloc)upperbound=min(upperbound,finalloc);
            bads[bafmodloc]=max(bads[bafmodloc],finalloc);//> is safe
            am++;
        }
    }
    vector<int> goods;
    for(int i=0;i<upperbound;i++){
        if(bads.count(i%p)&&i<=bads[i%p]){

        }
        else goods.push_back(i+st);
    }
    printf("%d\n",sz(goods));
    for(auto x:goods)printf("%d ",x);
    return 0;
}