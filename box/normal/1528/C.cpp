// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int lazput[300005<<2];

void tag(int idx,int l,int r,int v){
    lazput[idx]=v;
}

void pd(int idx,int l,int r){
    if(r-l==1)return;
    if(lazput[idx]==0)return;
    tag(idx*2,l,(l+r)/2,lazput[idx]);
    tag(idx*2+1,(l+r)/2,r,lazput[idx]);
    lazput[idx]=0;
}

void make(int idx,int l,int r,int L,int R,int v){
    if(L<=l&&r<=R)return tag(idx,l,r,v);
    if(R<=l||r<=L)return;
    pd(idx,l,r);
    make(idx*2,l,(l+r)/2,L,R,v);
    make(idx*2+1,(l+r)/2,r,L,R,v);
}

int qry(int idx,int l,int r,int x){
    if(!(l<=x&&x<r))return -1;
    if(r-l==1)return lazput[idx];
    pd(idx,l,r);
    return max(qry(idx*2,l,(l+r)/2,x),qry(idx*2+1,(l+r)/2,r,x));
}

int N=300001;

vector<int>S[300005],K[300005];
int L[300005], R[300005],clo=0;
int ans;

void reset(int n){
    rep1(i,n)S[i].clear(),K[i].clear();
    clo=0;
    ans=1;
    make(1,0,N,0,N,-1);
}

void dfsk(int u,int f){
    L[u]=clo++;
    for(int v:K[u])if(v!=f)dfsk(v,u);
    R[u]=clo;
}

void dfss(int u,int f,int curans){
    int C=qry(1,0,N,L[u]);
    if(C!=-1)
        make(1,0,N,L[C],R[C],-1),curans--;
    make(1,0,N,L[u],R[u],u),curans++;
    ans=max(ans,curans);
    for(int v:S[u])if(v!=f)dfss(v,u,curans);
    make(1,0,N,L[u],R[u],-1);
    if(C!=-1)
        make(1,0,N,L[C],R[C],C);
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;while(t--){
        int n;cin>>n;
        reset(n);
        iter(i,2,n+1){
            int f;cin>>f;
            S[f].pb(i);
        }
        iter(i,2,n+1){
            int f;cin>>f;
            K[f].pb(i);
        }
        dfsk(1,0);
        dfss(1,0,0);
        cout<<ans<<'\n';
    }
}