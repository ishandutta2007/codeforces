#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll arr[3];
int main(){
    setbuf(stdout,NULL);
    cin>>arr[0]>>arr[1]>>arr[2];
    ll sum=accumulate(arr,arr+3,ll(0));
    int ind=max_element(arr,arr+3)-arr;
    printf("First\n");
    printf("%lli\n",3*arr[ind]-sum);
    int te;
    cin>>te;
    if(te==-1)return 0;
    if(te-1!=ind){
        set<int> inds={0,1,2};
        inds.erase(te-1),inds.erase(ind);
        printf("%lli\n",arr[ind]-arr[*inds.begin()]);
        cin>>te;
        if(te==-1)return 0;
        assert(te==0);
        return 0;
    }
    arr[te-1]+=3*arr[ind]-sum;
    sum=accumulate(arr,arr+3,ll(0));
    printf("%lli\n",3*arr[ind]-sum);
    cin>>te;
    if(te==-1)return 0;
    if(te-1!=ind){
        set<int> inds={0,1,2};
        inds.erase(te-1),inds.erase(ind);
        printf("%lli\n",arr[ind]-arr[*inds.begin()]);
        cin>>te;
        if(te==-1)return 0;
        assert(te==0);
        return 0;
    }
    assert(0);
    return 0;
}