#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,m,k,rtyp[1000005],ctyp[1000005];
//0 - both ok
//1 - 0 start
//2 - 1 start
//3 - invalid
set<int> rs[4],cs[4];
map<int,int> rgrid[1000005],cgrid[1000005];
int rres[1000005][2],cres[1000005][2],mres[2];

void maketype(int x,int y){
    if(rres[x][0]&&rres[x][1])rtyp[x]=3;
    else if(rres[x][0])rtyp[x]=1;
    else if(rres[x][1])rtyp[x]=2;
    else rtyp[x]=0;
    rs[rtyp[x]].insert(x);
    if(cres[y][0]&&cres[y][1])ctyp[y]=3;
    else if(cres[y][0])ctyp[y]=1;
    else if(cres[y][1])ctyp[y]=2;
    else ctyp[y]=0;
    cs[ctyp[y]].insert(y);
}

void clear(int x,int y){
    if(rgrid[x].count(y)){
        mres[(x^y^rgrid[x][y])&1]--;
        rs[rtyp[x]].erase(x);
        rres[x][rgrid[x][y]^y&1]--;
        rgrid[x].erase(y);
        cs[ctyp[y]].erase(y);
        cres[y][cgrid[y][x]^x&1]--;
        cgrid[y].erase(x);
        maketype(x,y);
    }
}

void put(int x,int y,int val){
    clear(x,y);
    rs[rtyp[x]].erase(x);
    rres[x][val^y&1]++;
    rgrid[x][y]=val;
    cs[ctyp[y]].erase(y);
    cres[y][val^x&1]++;
    cgrid[y][x]=val;
    mres[(x^y^val)&1]++;
    maketype(x,y);
}

int get(){
    ll ans=(rs[3].empty()?qpow(2,rs[0].size()):0)+(cs[3].empty()?qpow(2,cs[0].size()):0);
    ans-=!mres[0];
    ans-=!mres[1];
    return (ans%mod+mod)%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<n;i++)rs[0].insert(i);
    for(int i=0;i<m;i++)cs[0].insert(i);
    while(k--){
        int x,y,t;
        cin>>x>>y>>t;
        x--;
        y--;
        if(t==-1){
            clear(x,y);
        }else put(x,y,t);
        cout<<get()<<'\n';
    }

    return 0;
}