#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
struct seg {
    struct node {
        int data, lazy;
    } t[2*MAXN];
    void rl(int ind, int left, int right, bool leaf){
        t[ind].data+=t[ind].lazy;
        if(!leaf){
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(ind,left,right,le==ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,left,right,le==ri);
            return;
        }
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
}tree;
int arr[MAXN];
int loc[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        loc[arr[i]]=i;
    }
    int ans=n;
    tree.update(1,1,n,1,loc[n],1);
    int a;
    printf("%d ",n);
    for(int i=1;i<n;i++){
        cin>>a;
        tree.update(1,1,n,1,a,-1);
        while(tree.t[1].data<=0){
            ans--;
            tree.update(1,1,n,1,loc[ans],1);
        }
        printf("%d ",ans);
    }
    return 0;
}