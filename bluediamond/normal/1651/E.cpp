#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;


const int inf=(int)1e9+7;
const int N=3000+7;
int n;
ll print;
vector<int> g[N],curpath;
bool vis[N];
vector<vector<int>> paths;

void dfs(int a){
        vis[a]=1;
        curpath.push_back(a);
        for(auto&b:g[a]){
                if(!vis[b]){
                        dfs(b);
                }
        }
}

ll mul(ll a, ll b) {return a*b;}
ll mul(ll a, ll b,ll c) {return a*b*c;}
ll mul(ll a, ll b,ll c,ll d) {return a*b*c*d;}
ll mul(ll a, ll b,ll c,ll d,ll e) {return a*b*c*d*e;}
ll mul(ll a, ll b,ll c,ll d,ll e,ll f) {return a*b*c*d*e*f;}
ll mul(ll a, ll b,ll c,ll d,ll e,ll f,ll g) {return a*b*c*d*e*f*g;}
ll mul(ll a, ll b,ll c,ll d,ll e,ll f,ll g,ll h) {return a*b*c*d*e*f*g*h;}

int mn1,mn2,mx1,mx2;

void upd(int x){
        if(1<=x&&x<=n){
                mn1=min(mn1,x);
                mx1=max(mx1,x);
        }else{
                mn2=min(mn2,x);
                mx2=max(mx2,x);
        }
}

vector<int> aux;

void cop(){
        assert(aux.empty());
        aux={mn1,mn2,mx1,mx2};
}

void place(){
        assert(!aux.empty());
        mn1=aux[0];
        mn2=aux[1];
        mx1=aux[2];
        mx2=aux[3];
        aux.clear();
}

ll get(){
        return mul(mn1,n+1-mx1,mn2-n,2*n+1-mx2);
}

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif

        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        cin>>n;
        for(int i=1;i<=2*n;i++){
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }

        for(int i=1;i<=2*n;i++){
                if(!vis[i]){
                        curpath.clear();
                        dfs(i);
                        paths.push_back(curpath);
                }
        }

        dfs(1);

        for(auto&path:paths){
                int dim=(int)path.size();
                assert(dim%2==0);
                /// times full
                {
                        ll t_full=0;

                        mn1=inf,mn2=inf,mx1=-inf,mx2=-inf;

                        for(auto&x:path){
                                upd(x);
                        }
                        print+=mul(dim/2,mn1,n+1-mx1,mn2-n,2*n+1-mx2);
                }
                for(int i=0;i<dim;i++){
                        mn1=inf,mn2=inf,mx1=-inf,mx2=-inf;
                        upd(path[i]);
                        for(int cnt=2;cnt<dim;cnt++){
                                ll matching=cnt/2;

                                upd(path[(i+cnt-1)%dim]);

                                int x1=path[i],y1=path[(i+dim-1)%dim];
                                int x2=path[(i+cnt-1)%dim],y2=path[(i+cnt)%dim];
                                vector<int> out={y1,y2};
                                if(y1<x1)swap(x1,y1);
                                if(y2<x2)swap(x2,y2);
                                assert(1<=x1&&x1<=n);
                                assert(1<=x2&&x2<=n);
                                assert(n+1<=y1&&y1<=2*n);
                                assert(n+1<=y2&&y2<=2*n);
                                ll total=0;
                                total+=get();
                                cop();
                                upd(x1); upd(y1);
                                total-=get();
                                place();
                                cop();
                                upd(x2); upd(y2);
                                total-=get();
                                place();
                                cop();
                                upd(x2); upd(y2); upd(x1); upd(y1);
                                total+=get();
                                place();


                                print+=mul(matching,total);

                        }
                }
        }
        cout<<print<<"\n";

        return 0;
        for(auto&path:paths){
                cout<<" ---> ";
                for(auto&x:path){
                        cout<<x<<" ";
                }
                cout<<"\n";
        }
}