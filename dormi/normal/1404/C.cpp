#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+1;
int arr[MAXN];
struct seg{
    struct node{
        vector<pii> rems;
        node(){
            rems={};
        }
    }t[2*MAXN];
    void build(int ind, int le, int ri){
        if(le==ri){
            t[ind].rems={{0,0}};
            if(arr[le]==le)t[ind].rems[0]={0,1};
            else if(arr[le]<le)t[ind].rems.push_back({le-arr[le],1});
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        build(left,le,mid),build(right,mid+1,ri);
        int r=0;
        for(int l=0;l<sz(t[left].rems);l++){
            int x=t[left].rems[l].first;
            t[ind].rems.push_back({x+max(0,t[right].rems[r].first-(x+t[left].rems[l].second)),t[left].rems[l].second+t[right].rems[r].second});
            while(r+1<sz(t[right].rems)&&max(0,t[right].rems[r+1].first-(x+t[left].rems[l].second))<(l+1==sz(t[left].rems)?INT_MAX:t[left].rems[l+1].first-t[left].rems[l].first)){
                r++;
                t[ind].rems.push_back({x+max(0,t[right].rems[r].first-(x+t[left].rems[l].second)),t[left].rems[l].second+t[right].rems[r].second});
            }
        }
        vector<pii> fin;
        for(auto x:t[ind].rems){
            while(sz(fin)&&fin.back().first==x.first)assert(fin.back().second<=x.second),fin.pop_back();
            if(sz(fin)==0||fin.back().second<x.second)fin.push_back(x);
        }
        t[ind].rems=fin;
    }
    int query(int ind, int le, int ri, int l, int r, int remed){
        if(l>ri||r<le)return remed;
        if(le>=l&&ri<=r){
            return remed+t[ind].rems[(upper_bound(t[ind].rems.begin(),t[ind].rems.end(),pii{remed,INT_MAX})-t[ind].rems.begin())-1].second;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        remed=query(left,le,mid,l,r,remed);
        remed=query(right,mid+1,ri,l,r,remed);
        return remed;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    tree.build(0,1,n);
    int l,r;
    while(q--){
        cin>>l>>r;
        printf("%d\n",tree.query(0,1,n,l+1,n-r,0));
    }
    return 0;
}