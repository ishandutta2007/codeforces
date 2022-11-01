#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

struct QUERY{
    int k,pos,id;
};

int n,m;
int A[200005];
pair<int,int> a[200005];
QUERY qry[200005];
int ans[200005];
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first;a[i].second=i;
        A[i]=a[i].first;
    }
    sort(a,a+n,[](pair<int,int> i,pair<int,int> j){
        if(i.first!=j.first)return i.first>j.first;
        return i.second<j.second;
    });
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>qry[i].k>>qry[i].pos;
        qry[i].id=i;
    }
    sort(qry,qry+m,[](QUERY i,QUERY j){
        if(i.k!=j.k)return i.k<j.k;
        else if(i.pos!=j.pos)return i.pos<j.pos;
        return i.id<j.id;
    });
    int cur=0;
    for(int i=0;i<m;i++){
        while(cur<qry[i].k)t.insert(a[cur++].second);
        ans[qry[i].id]=A[*t.find_by_order(qry[i].pos-1)];
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<endl;


    return 0;
}