#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
#define ALL(x) x.begin(),x.end()
#define f first
#define s second
#define pb emplace_back
#define mp make_pair
#define pb emplace_back

const int MAXN=200100;
vi groups[MAXN];
int N;
int A[MAXN];
int vis[MAXN];
int a=1;
vpi ans;
void dfs(int x,int h){
    groups[h].pb(x);
    vis[x]=1;
    if(!vis[A[x]])dfs(A[x],h);
}

void sw(int a,int b){
    swap(A[a],A[b]);
    A[a]=-A[a];
    A[b]=-A[b];
    ans.pb(a,b);
}

void res(int x,int l){
    if(!l)return;
    sw(abs(A[x]),x);
    res(x,l-1);
}

void fix(int a,int b){
    sw(groups[a][0], groups[b][0]);
    res(groups[b][0],groups[a].size()-1);
    res(groups[a][0],groups[b].size()-1);
    sw(groups[a][0], groups[b][0]);
}

void extfix(int a){
    if(groups[a].size()==2){
        int oth=-1;
        for(int i=1;i<=N;++i)if(A[i]==i){
            oth=i;
        }
        int x1=groups[a][0];
        int x2=groups[a][1];
        sw(x1,oth);
        sw(x2,oth);
        sw(x1,oth);
        // for(int i=1;i<=N;++i)cout<<A[i]<<' ';
        return;
    }
    int x=groups[a][0];
    int elec=A[x];
    sw(x,A[x]);
    // for(int i=1;i<=N;++i)cout<<A[i]<<' ';cerr<<'\n';
    res(x,groups[a].size()-3);
    // exactly 3 things leftover
    int neg=-1;
    int pos=-1;
    for(int i=1;i<=N;++i)if(abs(A[i])!=i){
        if(A[i]>0)pos=i;
        else neg=i;
    }
    assert(pos!=-1&&neg!=-1);
    sw(pos,elec);
    sw(neg,pos);
    sw(elec,neg);
}

int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>A[i];
    }
    for(int i=1;i<=N;++i){
        if(vis[i])continue;
        if(A[i]==i)continue;
        dfs(i,a);
        ++a;
    }
    --a;
    for(int i=1;i+1<=a;i+=2){
        fix(i,i+1);
    }
    if(a%2==1){
        extfix(a);
    }
    for(int i=1;i<=N;++i)assert(A[i]==i);
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i.f<<' '<<i.s<<'\n';
}