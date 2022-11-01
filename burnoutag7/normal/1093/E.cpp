#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int n,q;
int a[200005],b[200005],c[200005];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> bit[200005];

int sum(int pos,int l,int r){
    int res=0;
    while(pos>0){
        res+=bit[pos].order_of_key(r+1)-bit[pos].order_of_key(l);
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n){
        bit[pos].insert(val);
        pos+=pos&-pos;
    }
}

void del(int pos,int val){
    while(pos<=n){
        bit[pos].erase(val);
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i]=c[b[i]];
        add(i,b[i]);
    }
    swap(a,b);
    while(q--){
        char typ;
        cin>>typ;
        if(typ=='1'){
            int lv,rv,li,ri;
            cin>>lv>>rv>>li>>ri;
            cout<<sum(ri,lv,rv)-sum(li-1,lv,rv)<<'\n';
        }else{
            int l,r;
            cin>>l>>r;
            del(l,a[l]);
            del(r,a[r]);
            swap(a[l],a[r]);
            add(l,a[l]);
            add(r,a[r]);
        }
    }

    return 0;
}