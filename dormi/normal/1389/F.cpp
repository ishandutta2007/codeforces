#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+2;
struct seg{
    struct node{
        int data,lazy,data2;
        node(){data=0;lazy=0;data2=0;}
    }t[2*MAXN];
    void rl(int ind, int le, int ri){
        t[ind].data+=t[ind].lazy;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val, bool tp){
        rl(ind,le,ri);
        if(ri<l||le>r||l>r)return;
        if(le>=l&&ri<=r){
            if(tp){
                t[ind].data-=t[ind].data2;
                t[ind].data2=max(t[ind].data,val);
                t[ind].data+=t[ind].data2;
            }
            else {
                t[ind].lazy = val;
                rl(ind, le, ri);
            }
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val,tp),update(right,mid+1,ri,l,r,val,tp);
        t[ind].data=max(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(ri<l||le>r||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree[2];
vector<pair<pii,int>> segments;
vector<int> points;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    int n;
    cin>>n;
    segments.resize(n);
    for(int i=0;i<n;i++){
        cin>>segments[i].first.first>>segments[i].first.second>>segments[i].second;
        segments[i].second-=1;
        points.push_back(segments[i].first.second);
    }
    points.push_back(0);
    sort(points.begin(),points.end());
    points.erase(unique(points.begin(),points.end()),points.end());
    sort(segments.begin(),segments.end(),[&](auto lhs, auto rhs){
        if(lhs.first.second==rhs.first.second)return lhs.first.first<rhs.first.first;
        return lhs.first.second<rhs.first.second;
    });
    for(auto x:segments){
        int loc=lower_bound(points.begin(),points.end(),x.first.first)-points.begin();
        int loc2=lower_bound(points.begin(),points.end(),x.first.second)-points.begin();
        int best=tree[!x.second].query(0,0,sz(points)-1,0,loc-1)+1;
        tree[!x.second].update(0,0,sz(points)-1,0,loc-1,1,0);
        tree[x.second].update(0,0,sz(points)-1,loc2,loc2,best,1);
    }
    printf("%lli\n",max(tree[0].query(0,0,sz(points)-1,0,sz(points)-1),tree[1].query(0,0,sz(points)-1,0,sz(points)-1)));
    return 0;
}