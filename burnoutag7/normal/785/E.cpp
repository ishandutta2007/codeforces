#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int n,q;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> bit[200005];

int sum(int x,int y){
    int res=0;
    while(x>0){
        res+=bit[x].order_of_key(y);
        x-=x&-x;
    }
    return res;
}

void add(int x,int y){
    while(x<=n){
        bit[x].insert(y);
        x+=x&-x;
    }
}

void del(int x,int y){
    while(x<=n){
        bit[x].erase(y);
        x+=x&-x;
    }
}

int a[200005];

long long ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        add(i,i);
        a[i]=i;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l>r)swap(l,r);
        del(l,a[l]);
        del(r,a[r]);
        ans+=(sum(r,a[r])-sum(l,a[r])<<1)-(r-l-1);
        ans+=(r-l-1)-(sum(r,a[l])-sum(l,a[l])<<1);
        ans+=(a[r]>a[l])-(a[r]<a[l]);
        swap(a[l],a[r]);
        add(l,a[l]);
        add(r,a[r]);
        cout<<ans<<'\n';
    }

    return 0;
}