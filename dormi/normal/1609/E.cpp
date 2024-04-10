#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
struct seg{
    struct node{
        int data;
        int lazy;
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
        if(l>r||l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].data=min(t[left].data,t[right].data);
    }
}tree;
struct seg2{
    struct node{
        int data1,data2,data3;
        int lazy1,lazy2;
        node(){
            data1=0,data2=0,data3=0;
            lazy1=0,lazy2=0;
        }
        void apply(int v1, int v2){
            lazy1+=v1;
            lazy2+=v2;
            data1+=v1;
            data2+=v2;
            data3+=v1+v2;
        }
    }t[2*MN];
    void prop(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy1,t[ind].lazy2),t[right].apply(t[ind].lazy1,t[ind].lazy2);
        t[ind].lazy1=0,t[ind].lazy2=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v1, int v2){
        if(l>r||l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v1,v2);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v1,v2),update(right,mid+1,ri,l,r,v1,v2);
        t[ind].data1=min(t[left].data1,t[right].data1);
        t[ind].data2=min(t[left].data2,t[right].data2);
        t[ind].data3=min({t[left].data3,t[right].data3,t[left].data1+t[right].data2});
    }
}tree2;
char arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int acnt=0;
    for(int i=1;i<=n;i++){
        if(arr[i]=='a'){
            acnt++;
            tree.update(0,1,n,i+1,n,1);
            tree2.update(0,1,n,i+1,n,1,0);
        }
        else if(arr[i]=='b'){
            tree.update(0,1,n,1,i-1,1);
            tree2.update(0,1,n,i+1,n,-1,1);
        }
        else{
            tree2.update(0,1,n,1,i-1,0,1);
        }
    }
    int loc;
    char c;
    auto check=[&](int ind, int mut){
        if(arr[ind]=='a'){
            acnt+=mut;
            tree.update(0,1,n,ind+1,n,mut);
            tree2.update(0,1,n,ind+1,n,mut,0);
        }
        else if(arr[ind]=='b'){
            tree.update(0,1,n,1,ind-1,mut);
            tree2.update(0,1,n,ind+1,n,-mut,mut);
        }
        else{
            tree2.update(0,1,n,1,ind-1,0,mut);
        }
    };
    while(q--){
        cin>>loc>>c;
        check(loc,-1);
        arr[loc]=c;
        check(loc,1);
        printf("%d\n",min({acnt,tree.t[0].data,tree2.t[0].data3}));
    }
    return 0;
}