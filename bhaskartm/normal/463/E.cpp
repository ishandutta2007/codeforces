#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
using namespace std;
const int NMAX  = 100004;
const int VALMAX = 2e6;
vector < int > Tree[NMAX];
int value[NMAX], niv[NMAX] , answer[NMAX];
bitset < VALMAX+6> viz;
int prime[2*NMAX],pos[6+VALMAX];
stack < int > St[2*NMAX]; 
inline void Eratosthenes(){
    prime[++prime[0]] = 2; 
    pos[2] = 1;
    for(int i = 3;i <= VALMAX;i += 2)
        if(!viz[i]){
            prime[++prime[0]] = i;
            pos[i] = prime[0];
            for(long long j = 1LL*i*i;j <= VALMAX; j += 2*i)
                viz[j] = 1;
        }
}
inline void DFS(const int node,const int father){
    vector < int > v;
    int d = 2,step = 1;
    int x = value[node];
    answer[node] = 0;
    while(d*d <= x){
        if(x%d==0){
            if(!St[pos[d]].empty()){
                int y = St[pos[d]].top();
                if(niv[y] > niv[answer[node]])
                    answer[node] = y;
            }
            v.push_back(pos[d]);
            St[pos[d]].push(node);
            while(x%d==0)
                x /= d;
        }
        ++step;
        d = prime[step];
    }
    if(x > 1){
        if(!St[pos[x]].empty()){
            int y = St[pos[x]].top();
            if(niv[y] > niv[answer[node]])
                 answer[node] = y;
        }
        v.push_back(pos[x]);
        St[pos[x]].push(node);
    }
    for(vector < int > ::iterator it = Tree[node].begin(); it != Tree[node].end(); ++it)
        if(*it!=father){
            niv[*it] = niv[node] + 1;
            DFS(*it,node);
        }
    for(vector < int > ::iterator it = v.begin(); it != v.end() ; ++it)
        St[*it].pop();
    v.clear();
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
        freopen("date.ok","w",stdout);
    #endif
    cin.sync_with_stdio(false);
    Eratosthenes();
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n; ++i)
        cin >> value[i];
    for(int i = 1;i < n; ++i){
        int x, y;
        cin >> x >> y;
        Tree[x].push_back(y);
        Tree[y].push_back(x);
    }
    niv[1] = 1;
    DFS(1,-1);
    while(m--){
        int operation, x, y;
        cin >> operation >> x;
        if(operation == 1){
            if(answer[x] > 0)
                cout<<answer[x]<<"\n";
            else
                cout<<"-1\n";
        }
        else{
            cin >> y;
            value[x] = y;
            DFS(1,-1);
        }
    }
    return 0;
}