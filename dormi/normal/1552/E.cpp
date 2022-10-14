#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=101*101;
int am[MN];
int arr[MN];
vector<int> ord[MN];
pii used[MN];
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int v){
            data+=v;
            lazy+=v;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=max(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return INT_MIN;
        if(le>=l&&ri<=r)return t[ind].data;
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)used[i]={-1,-1};
    for(int i=1;i<=n*k;i++){
        cin>>arr[i];
        ord[arr[i]].push_back(i);
    }
    int limit=(n+k-2)/(k-1);
    int endind=n*k;
    for(int i=1;i<=n;i++){
        bool done=false;
        int mi=INT_MAX;
        for(int j=1;j<=n;j++){
            if(used[j].first==-1){
                for(int l=1;l<sz(ord[j]);l++){
                    int te=tree.query(0,1,endind,ord[j][l-1],ord[j][l])+1;
                    if(te<=limit){
                        mi=min(mi,ord[j][l]);
                    }
                }
            }
        }
        for(int j=1;j<=n&&!done;j++){
            if(used[j].first==-1){
                for(int l=1;l<sz(ord[j]);l++){
                    int te=tree.query(0,1,endind,ord[j][l-1],ord[j][l])+1;
                    if(te<=limit&&ord[j][l]==mi){
                        done=true;
                        used[j]={ord[j][l-1],ord[j][l]};
                        tree.update(0,1,endind,ord[j][l-1],ord[j][l],1);
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",used[i].first,used[i].second);
    return 0;
}