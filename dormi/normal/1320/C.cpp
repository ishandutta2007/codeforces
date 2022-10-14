#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli bit[MAXN];
int n,m,p;

void update(int loc, lli val){
    for(;loc<=p;loc+=loc&-loc)bit[loc]+=val;
}
lli query(int loc){
    lli sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
pair<pll,int> weps[MAXN];
pair<pll,int> arms[MAXN];
vector<pll> armu;
vector<pll> armute;
vector<pll> wepu;
vector<pll> wepute;
map<lli,lli> chw;
map<lli,lli> cha;
pair<pll,pair<lli,int>> mon[MAXN];
int id[MAXN];
vector<lli> withthis;
struct node{
    lli data,lazy;
    int le, ri;
    struct node* left,*right;
    node(){
        data=0,lazy=0;
        le=0,ri=0;
        left=NULL;
        right=NULL;
    }
    int mid(){
        return(le+ri)/2;
    }
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left= new node(),right=new node();
            left->mt(le,mid());
            right->mt(mid()+1,ri);
            data=max(left->data,right->data);
        }
    }
    void rl(){
        data+=lazy;
        if(le!=ri){
            left->lazy+=lazy,right->lazy+=lazy;
        }
        lazy=0;
    }
    void update(int l, int r, lli val){
        rl();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            lazy=val;
            rl();
            return;
        }
        left->update(l,r,val),right->update(l,r,val);
        data=max(left->data,right->data);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>p;
    lli chep=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>weps[i].first.first>>weps[i].first.second;
        chep=min(chep,weps[i].first.second);
        if(!chw.count(weps[i].first.first))chw[weps[i].first.first]=weps[i].first.second;
        else chw[weps[i].first.first]=min(chw[weps[i].first.first],weps[i].first.second);
        weps[i].second=i;
    }
    for(int i=0;i<n;i++){
        if(weps[i].first.second==chw[weps[i].first.first]){
            wepute.push_back(weps[i].first);
            chw[weps[i].first.first]=0;
        }
        else assert(chw[weps[i].first.first]<weps[i].first.second);
    }
    sort(wepute.begin(),wepute.end());
    wepu.push_back(wepute[sz(wepute)-1]);
    for(int i=sz(wepute)-2;i>=0;i--){
        if(wepute[i].second<wepu.back().second){
            wepu.push_back(wepute[i]);
        }
    }
    reverse(wepu.begin(),wepu.end());
    assert(is_sorted(wepu.begin(),wepu.end()));
    lli chep2=LLONG_MAX;
    for(int i=0;i<m;i++){
        cin>>arms[i].first.first>>arms[i].first.second;
        chep2=min(chep2,arms[i].first.second);
        if(!cha.count(arms[i].first.first))cha[arms[i].first.first]=arms[i].first.second;
        else cha[arms[i].first.first]=min(cha[arms[i].first.first],arms[i].first.second);
        arms[i].second=i;
    }
    for(int i=0;i<m;i++){
        if(arms[i].first.second==cha[arms[i].first.first]){
            armute.push_back(arms[i].first);
            cha[arms[i].first.first]=0;
        }
        else assert(cha[arms[i].first.first]<arms[i].first.second);
    }
    sort(armute.begin(),armute.end());
    armu.push_back(armute[sz(armute)-1]);
    for(int i=sz(armute)-2;i>=0;i--){
        if(armute[i].second<armu.back().second){
            armu.push_back(armute[i]);
        }
    }
    reverse(armu.begin(),armu.end());
    assert(is_sorted(armu.begin(),armu.end()));
    for(int i=0;i<p;i++){
        cin>>mon[i].first.first>>mon[i].first.second>>mon[i].second.first;
        mon[i].second.second=i;
    }
    sort(mon,mon+p,[&](auto a, auto b){
        if(a.first.second==b.first.second)return a<b;
        return a.first.second<b.first.second;
    });
    node tree;
    tree.mt(1,p);
    withthis.push_back(0);
    int l2=0;
    for(int i=0;i<p;i++){
        id[mon[i].second.second]=i+1;
        withthis.push_back(mon[i].first.second);
        while(l2<sz(armu)&&armu[l2].first<=mon[i].first.second)l2++;
        if(l2==sz(armu))tree.update(i+1,i+1,-1e15);
        else tree.update(i+1,i+1,-armu[l2].second);
    }
    sort(mon,mon+p);

    int l=0;
    lli ans=-(chep+chep2);
    for(auto x:wepu){
        while(l<p&&mon[l].first.first<x.first){
            tree.update(id[mon[l].second.second],p,mon[l].second.first);
            l++;
        }
        ans=max(ans,tree.data-x.second);
    }
    printf("%lli\n",ans);
    return 0;
}