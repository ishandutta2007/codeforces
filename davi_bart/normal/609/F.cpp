#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N,M;
int dim=(int)1<<31;
struct node{
    int l, r,mi;
    node(){
        l=-1;
        r=-1;
        mi=1e18;
    }
};
vector<node> s(1);
node def;
void addleft(int pos){
    if(s[pos].l!=-1)return;
    s.pb(def);
    s[pos].l=s.size()-1;
}
void addright(int pos){
    if(s[pos].r!=-1)return;
    s.pb(def);
    s[pos].r=s.size()-1;
}
int getmi(int pos){
    if(pos==-1)return 1e18;
    return s[pos].mi;
}
void upd(int pos,int l,int r,int k,int val){
    if(l>k || r<k)return;
    if(l==r){
        s[pos].mi=min(s[pos].mi,val);
        return;
    }
    int m=(l+r)/2;
    if(k<=m){
        addleft(pos);
        upd(s[pos].l,l,m,k,val);
    }else{
        addright(pos);
        upd(s[pos].r,m+1,r,k,val);
    }
    s[pos].mi=min(getmi(s[pos].l),getmi(s[pos].r));
}

int best(int pos,int l,int r,int a,int b){
    if(r<a || b<l)return 1e14;
    if(l>=a && r<=b)return getmi(pos);
    int m=(l+r)/2;
    addleft(pos);
    addright(pos);
    return min(best(s[pos].l,l,m,a,b),best(s[pos].r,m+1,r,a,b));
}
map<int,int> rane;
vector<int> xx(200010);
vector<int> lingua(200010);
vector<int> ans(200010);
multiset<pair<int,int> >mosche;
void mangia(int pos){
    pair<int,int> q={xx[pos],-10};
    auto y=mosche.lower_bound(q);
    vector<pair<int,int> >togli;
    while(y!=mosche.end()){
        auto [a,b]=*y;
        if(a>xx[pos]+lingua[pos])break;
        togli.pb({a,b});
        lingua[pos]+=b;
        ans[pos]++;
        y++;
    }
    for(auto h:togli)mosche.erase(mosche.find(h));
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>N>>M;
    vector<int> p;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        upd(0,0,dim-1,min(dim-1,a+b),a);
        lingua[i]=b;
        rane[a]=i;
        xx[i]=a;
        p.pb(i);
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        int x=best(0,0,dim-1,a,dim-1);
        if(x<=a){
            int pos=rane[x];
            ans[pos]++;
            lingua[pos]+=b;
            mangia(pos);
            upd(0,0,dim-1,min(dim-1,xx[pos]+lingua[pos]),xx[pos]);
        }else{
            mosche.insert({a,b});
        }
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<" "<<lingua[i]<<'\n';
    }
}