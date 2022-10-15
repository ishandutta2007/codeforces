#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

const int MAXN = 100100;

int a,b,c,T,N,K;
vi V[MAXN];
int dp1[MAXN];
int dp2[MAXN];
map<pi,bool> M;
vpi R,L,B;
int deg[MAXN];
pi ep[MAXN];

void query(int x,int p){
    int c=0;
    for(auto v:V[x])if(v!=p){
        ++c;
        query(v,x);
    }

    // option 1 you HAVE an up
    vi tx;
    dp1[x]=c;
    for(auto v:V[x])if(v!=p){
        dp1[x]+=dp2[v];
        tx.pb(dp1[v]-dp2[v]);
    }
    int W=dp1[x];
    sort(ALL(tx));
    // you have 1 down and 1 up
    if(c>0){
        dp1[x] = min(dp1[x],W+tx[0]-1);
    }

    // option 2 you do NOT have an up

    dp2[x]=c;
    for(auto v:V[x])if(v!=p){
        dp2[x]+=dp2[v];
    }
    W=dp2[x];
    // you have 1 down
    if(c>0){
        dp2[x] = min(dp2[x], W+tx[0]-1);
    }
    if(c>1){
        dp2[x]=min(dp2[x],W+tx[0]+tx[1]-2);
    }

    if(p==-1){
        dp1[x]=1e9;
    }
}

void resolve(int x,int p,int o){
    int l=0;int c=0;
    vpi tx;
    for(auto v:V[x])if(v!=p){
        l+=dp2[v];++c;
        tx.pb(dp1[v]-dp2[v],v);
    }
    sort(ALL(tx));
    // cerr<<x<<' '<<c+l<<'\n';

    if(o==1){
        // using option 1 - you have an up

        int d=c+l;
        if(d==dp1[x]){
            for(auto v:V[x])if(v!=p){
                R.pb(x,v);
                resolve(v,x,2); // no ups
            }
        }else{
            L.pb(x,tx[0].s);
            resolve(tx[0].s,x,1); // goes up 
            for(auto v:V[x])if(v!=p&&v!=tx[0].s){
                R.pb(x,v);
                resolve(v,x,2); // no ups
            }
        }
    }

    if (o == 2){ // you have no ups
        int d=c+l;
        if(d==dp2[x]){
            for(auto v:V[x])if(v!=p){
                R.pb(x,v);
                resolve(v,x,2); // no ups
            }
        }else if(d+tx[0].f-1 == dp2[x]){
            L.pb(x,tx[0].s);
            resolve(tx[0].s,x,1);
            for(auto v:V[x])if(v!=p&&v!=tx[0].s){
                R.pb(x,v);
                resolve(v,x,2); // no ups
            }
        }else{
            L.pb(x,tx[0].s);
            L.pb(x,tx[1].s);
            resolve(tx[1].s,x,1);
            resolve(tx[0].s,x,1);
            for(auto v:V[x])if(v!=p&&v!=tx[0].s&&v!=tx[1].s){
                R.pb(x,v);
                resolve(v,x,2); // no ups
            }
        }
    }
}

int main(){
    cin>>T;
    while(T--){
        cin>>N;M.clear();R.clear();
        L.clear();B.clear();
        for(int i=1;i<=N;++i){
            V[i].clear();
            dp1[i]=dp2[i]=0;
        }
        for(int i=1;i<N;++i){
            cin>>a>>b;
            V[a].pb(b);
            V[b].pb(a);
        }
        query(1,-1);
        cout<<dp2[1]<<'\n';
        resolve(1,-1,2);
        
        for(int i=1;i<=N;++i){
            ep[i]=mp(i,i);
        }
        for(auto i:L){
            int a=i.f;
            int b=i.s;
            int c=ep[a].f+ep[a].s-a;
            int d=ep[b].f+ep[b].s-b;
            ep[a]=ep[b]=mp(-1,-1);
            ep[c]=ep[d]=mp(c,d);
        }
        vi ww;
        // cerr<<SZ(ww)<<'\n';
        for(int i=1;i<=N;++i)if(ep[i].f==i)ww.pb(i);
        // cerr<<SZ(ww)<<'\n';
        for(int i=0;i<SZ(ww)-1;++i){
            B.pb(ep[ww[i]].s, ep[ww[i+1]].f);
        }
        assert(SZ(R)==SZ(B));
        for(int i=0;i<SZ(R);++i){
            cout<<R[i].f<<' '<<R[i].s<<' '<<B[i].f<<' '<<B[i].s<<'\n';
        }
    }
}