#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=75001;
const ll mod=1e9;
struct func{
    vector<pair<pll,ll>> arr;
    func(){arr={};}
    ll calc(ll x){
        int ind=lower_bound(arr.begin(),arr.end(),x,[&](auto it, auto val){
           return it.second<val;
        })-arr.begin();
        return arr[ind].first.first*x+arr[ind].first.second;
    }
};
func uni(func* a, func* b){
    int l=0,r=0;
    func final;
    while(l<sz(a->arr)){
        if(a->arr[l].second>b->arr[r].second)swap(a,b),swap(l,r);
        final.arr.push_back({{a->arr[l].first.first+b->arr[r].first.first,a->arr[l].first.second+b->arr[r].first.second},a->arr[l].second});
        if(a->arr[l].second==b->arr[r].second)r++;
        l++;
    }
    return final;
}
func arr[MAXN];
struct seg{
    func t[2*MAXN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=arr[le];
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=uni(&t[left],&t[right]);
    }
    ll query(int ind, int le, int ri, int l, int r, ll loc){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].calc(loc);
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r,loc)+query(right,mid+1,ri,l,r,loc);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll x1,x2,y1,a,b,y2;
    for(int i=1;i<=n;i++){
        cin>>x1>>x2>>y1>>a>>b>>y2;
        arr[i].arr.push_back({{0,y1},x1});
        arr[i].arr.push_back({{a,b},x2});
        arr[i].arr.push_back({{0,y2},LLONG_MAX});
    }
    tree.mt(0,1,n);
    int m;
    cin>>m;
    ll last=0;
    ll x;
    int l,r;
    while(m--){
        cin>>l>>r>>x;
        x=(x+last)%mod;
        printf("%lli\n",last=tree.query(0,1,n,l,r,x));
    }
    return 0;
}