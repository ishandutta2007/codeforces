#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K=700;

struct query{
    int l,r,id;
    query(int _l=0,int _r=0,int _id=0){l=_l;r=_r;id=_id;}
    bool operator<(query &q)const{return make_pair(l,r)<make_pair(q.l,q.r);}
};

int a[200005];
ll ans[200005];
vector<query> q[200005/K+5];
int c[1000005];
ll val,n,t;

inline void dec(int &v){
    val-=(ll)v*((c[v]<<1)-1);
    c[v]--;
}

inline void inc(int &v){
    val+=(ll)v*((c[v]<<1)+1);
    c[v]++;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<t;i++){
        int x,y,r;cin>>x>>y;
        r=y/K;
        q[r].push_back(query(x,y,i));
    }
    int l=1,r=0;
    val=0;
    for(int i=0;i<=n/K;i++){
        sort(q[i].begin(),q[i].end());
        for(int j=0;j<q[i].size();j++){
            query &w=q[i][j];
            while(l<w.l)dec(a[l++]);
            while(l>w.l)inc(a[--l]);
            while(r<w.r)inc(a[++r]);
            while(r>w.r)dec(a[r--]);
            ans[w.id]=val;
        }
    }
    for(int i=0;i<t;i++)cout<<ans[i]<<endl;

    return 0;
}