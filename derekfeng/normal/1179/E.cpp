#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
map<ll,ll>mp[1004];
int n;ll lst,L,D,ansl[1004],ansr[1004];
mt19937 rng(114514);
ll ask(int x,ll t){
    if(mp[x].count(t))return mp[x][t];
    printf("? %d %lld\n",x,t);
    fflush(stdout);
    ll w;scanf("%lld",&w);
    fflush(stdout);
    mp[x][t]=w;return w;
}
ll bs(int x,ll w){
    ll l=lst-1,r=inf+1;
    while(r>l+1){
        ll md=(l+r)>>1;
        if(ask(x,md)>=w)r=md;
        else l=md;
    }
    return r;
}
ll calc(vector<int>v,ll w,int k){
    int t=rng()%(int)v.size();
    ll pos=bs(v[t],w);
    vector<int>A,B,C;C.push_back(v[t]);
    for(auto x:v)if(x!=v[t]){
        ll W=ask(x,pos);
        if(W<w)B.push_back(x);
        else if(W>w)A.push_back(x);
        else C.push_back(x);
    }
    if(A.size()>=k)return calc(A,w,k);
    if(A.size()+C.size()>=k)return pos;
    return calc(B,w,k-A.size()-C.size());
}
void sol(vector<int>vec,ll L,ll R){
    int n=vec.size();
    if(n==1){
        ansl[vec[0]]=lst;
        ansr[vec[0]]=bs(vec[0],R);
        lst=ansr[vec[0]];
        return;
    }
    int pl=(n+1)>>1,pr=n-pl;
    ll V=L+D*pl;
    ll pos=calc(vec,V,pl);
    vector<int>A,B,C;
    for(auto x:vec){
        ll W=ask(x,pos);
        if(W<V)B.push_back(x);
        else if(W>V)A.push_back(x);
        else C.push_back(x);
    }
    int it=0;
    while(A.size()<pl)A.push_back(C[it++]);
    while(B.size()<pr)B.push_back(C[it++]);
    sol(A,L,V),sol(B,V,R);
}
int main(){
    scanf("%d%lld",&n,&L);
    fflush(stdout);D=L/n;
    if(L<n){
        puts("!");
        for(int i=1;i<=n;i++)puts("0 0");
        return 0;
    }
    vector<int>vec;
    for(int i=1;i<=n;i++)vec.push_back(i);
    random_shuffle(vec.begin(),vec.end());
    sol(vec,0,L);
    puts("!");
    for(int i=1;i<=n;i++)printf("%lld %lld\n",ansl[i],ansr[i]);
}