#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> e;
        vector<vector<int>> g(n),init;
        for(int i=0;i<n-1;i++){
                int a,b;
                cin>>a>>b;
                a--;
                b--;
                e.push_back({a, b});
                g[a].push_back(b);
                g[b].push_back(a);
        }

        init=g;

        vector<int> maxDown(n,0),maxUp(n,0),dl(n,0);

        function<void(int,int)>dfsDown=[&](int a,int p){
                maxDown[a]=0;
                vector<int> K;
                for(auto&b:g[a]){
                        if(b!=p){
                                dl[b]=1^dl[a];
                                dfsDown(b,a);

                                maxDown[a]=max(maxDown[a],1+maxDown[b]);
                                K.push_back(b);
                        }
                }
                g[a]=K;
        };

        function<void(int)>dfsUp=[&](int a){
                for(int S=0;S<2;S++){
                        int MX=0;
                        for(auto&b:g[a]){
                                maxUp[b]=max(maxUp[b],1+MX);
                                maxUp[b]=max(maxUp[b],1+maxUp[a]);
                                MX=max(MX,1+maxDown[b]);
                        }
                        reverse(g[a].begin(),g[a].end());
                }
                for(auto&b:g[a]){
                        dfsUp(b);
                }
        };

        dfsDown(0,-1);
        if(k==2){
                cout<<"Yes\n";
                for(auto&x:dl){
                        cout<<x+1<<" ";
                }
                exit(0);
        }
        dfsUp(0);

        if(home){
        for(int i=0;i<n;i++){
                cout<<"down["<<i+1<<"] = "<<maxDown[i]<<"\n";
        }

        for(int i=0;i<n;i++){
                cout<<"up["<<i+1<<"] = "<<maxUp[i]<<"\n";
        }
        }


        for(int i=0;i<n;i++){
                if((int)g[i].size()+(i!=0)>=3){
                        vector<int> G;
                        if(i)G.push_back(maxUp[i]);
                        for(auto&b:g[i]){
                                G.push_back(1+maxDown[b]);
                        }
                        sort(G.rbegin(),G.rend());

                        if(home){
                                cout<<i<<" : ";
                                for(int j=0;j<(int)G.size();j++){
                                        cout<<G[j]<<" ";
                                }
                                cout<<" ---> ";
                        }

                        if(G[1]+G[2]>=k-1){
                                cout<<"No\n";
                                return 0;
                        }
                }
        }
        cout<<"Yes\n";
        g=init;
        vector<int> dist(n),ant(n);

        function<int(int)> bfs=[&](int root){
                for(int i=0;i<n;i++){
                        dist[i]=-1;
                }
                vector<int> q={root};
                dist[root]=0;
                for(int ind=0;ind<(int)q.size();ind++){
                        int a=q[ind];
                        for(auto&b:g[a]){
                                if(dist[b]==-1){
                                        ant[b]=a;
                                        dist[b]=1+dist[a];
                                        q.push_back(b);
                                }
                        }
                }
                int j=0;
                for(int i=1;i<n;i++){
                        if(dist[i]>dist[j]){
                                j=i;
                        }
                }
                return j;
        };


        int a=bfs(0);
        int b=bfs(a);

        vector<int> path,sol(n,-1);

        for(int j=b;j!=a;j=ant[j]){
                path.push_back(j);
        }
        path.push_back(a);
        int cur=1;

        for(auto&x:path){
                sol[x]=cur;
                if(cur==k)
                        cur=1;
                else
                        cur++;
        }

        function<void(int,int)>go=[&](int a,int dir){
                assert(sol[a]!=-1);
                for(auto&b:g[a]){
                        if(sol[b]==-1){
                                sol[b]=sol[a]+dir;
                                if(sol[b]<0){
                                        sol[b]=k;
                                }
                                if(sol[b]>k){
                                        sol[b]=1;
                                }
                                go(b,dir);
                        }
                }
        };
        for(int i=0;i<(int)path.size();i++){
                if(i<(int)path.size()/2){
                        go(path[i],-1);
                }else{
                        go(path[i],+1);
                }
        }

        if(home&&0){
                for(auto&it:e){
                        cout<<it.first<<"("<<sol[it.first]<<") "<<it.second<<"("<<sol[it.second]<<")\n";
                }
                exit(0);

        }
        for(auto&x:sol){
                assert(x!=-1);
                cout<<x<<" ";
        }
        cout<<"\n";


        return 0;
}