#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5;

int t;
int n,m,k;
vector<int> graph[NMAX + 5];
int gr[NMAX + 5];
bool active[NMAX + 5];
bool in[NMAX + 5];

bool exists(int i,int j){
    vector<int> :: iterator it = lower_bound(graph[i].begin(),graph[i].end(),j);
    if(it != graph[i].end() && *it == j){
        return true;
    }
    return false;
}

int main(){

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&n,&m,&k);

        for(int i = 1;i <= n;i++){
            gr[i] = 0;
            graph[i].clear();
            active[i] = 1;
            in[i] = 0;
        }

        for(int i = 1;i <= m;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            gr[u]++;
            gr[v]++;
        }

        if(1LL * k * (k - 1) > 2 * m){
            printf("-1\n");
            continue;
        }
        
        queue<int> q;

        for(int i = 1;i <= n;i++){
            sort(graph[i].begin(),graph[i].end());
            if(gr[i] < k){
                q.push(i);
                in[i] = 1;
            }
        }

        while(!q.empty()){
            int nod = q.front();
            active[nod] = 0;
            q.pop();
            for(auto it:graph[nod]){
                gr[it]--;
                if(in[it] == 0 && gr[it] < k){
                    in[it] = 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans;

        for(int i = 1;i <= n;i++){
            if(active[i] == 1){
                ans.push_back(i);
            }
        }

        if(ans.empty() == false){
            printf("1 %d\n",(int)ans.size());
            for(auto it:ans){
                printf("%d ",it);
            }
            printf("\n");
            continue;
        }

        for(int i = 1;i <= n;i++){
            gr[i] = graph[i].size();
            active[i] = 1;
            in[i] = 0;
        }

        for(int i = 1;i <= n;i++){
            if(gr[i] < k){
                in[i] = 1;
                q.push(i);
            }
        }

        bool found = false;

        while(!q.empty()){
            int nod = q.front();
            q.pop();
            active[nod] = 0;
            if(gr[nod] == k - 1){
                vector<int> nodes = {nod};
                for(auto it:graph[nod]){
                    if(active[it] == 1){
                        nodes.push_back(it);
                    }
                }
    
                bool ok = true;
    
                for(int i = 0;i < (int)nodes.size() && ok;i++){
                    for(int j = i + 1;j < (int)nodes.size() && ok;j++){
                        ok &= exists(nodes[i],nodes[j]);
                    }
                }
    
                if(ok == true){
                    found = true;
                    printf("2\n");
                    for(auto it:nodes){
                        printf("%d ",it);
                    }
                    printf("\n");
                    break;
                }
            }

            for(auto it:graph[nod]){
                gr[it]--;
                if(in[it] == 0 && gr[it] < k){
                    in[it] = 1;
                    q.push(it);
                }
            }
        }

        if(found == false){
            printf("-1\n");
            continue;
        }
    }

    return 0;
}