#include <bits/stdc++.h>

using namespace std;

bool home = 1;


typedef long long ll;
const int N=(int)3e5+7;
int n,m,types[N],ff[N],ss[N],fortnite[N];
vector<int> g[N];
vector<int> impl[N];
vector<int> nodes;
vector<int> w[N];

bool vis[N];
bool act[N];
int temp;
int t[N];

void push(int a){
        vis[a]=act[a]=1;
        for(auto&b:impl[a]){
                if(act[b]){
                        cout<<"NO\n";
                        exit(0);
                }
                if(!vis[b]){
                        push(b);
                }
        }
        t[a]=++temp;
        act[a]=0;
}

void color(int a){
        nodes.push_back(a);
        for(auto&b:g[a]){
                if(fortnite[b]==fortnite[a]){
                        cout<<"NO\n";
                        exit(0);
                }
                if(fortnite[b]==-1){
                        fortnite[b]=1^fortnite[a];
                        color(b);
                }
        }
}

int main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        cin>>n>>m;
        for(int i=1;i<=m;i++){
                cin>>types[i]>>ff[i]>>ss[i];
                g[ff[i]].push_back(ss[i]);
                g[ss[i]].push_back(ff[i]);
                w[ff[i]].push_back(i);
        }

        for(int i=1;i<=n;i++){
                fortnite[i]=-1;
        }
        for(int i=1;i<=n;i++){
                if(fortnite[i]==-1){
                        nodes.clear();
                        fortnite[i]=0;
                        color(i);
                        for(auto&V:nodes){
                                for(auto&i:w[V]){
                                        if(fortnite[ff[i]]==1)swap(ff[i],ss[i]);
                                        assert(fortnite[ff[i]]==0&&fortnite[ss[i]]==1);
                                        if(types[i]==1){
                                                impl[ff[i]].push_back(ss[i]);
                                        }else{
                                                impl[ss[i]].push_back(ff[i]);
                                        }
                                }
                        }
                        for(auto&V:nodes){
                                if(!vis[V]){
                                        push(V);
                                }
                        }
                }

        }


        cout<<"YES\n";
        for(int i=1;i<=n;i++){
                if(fortnite[i]){
                        cout<<"L ";
                }else{
                        cout<<"R ";
                }
                cout<<t[i]<<"\n";
        }

        return 0;
}