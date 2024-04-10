#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int dist[MAXN];
map<int,int> vals[MAXN];
int path[MAXN];
vector<int> othmat[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[b].push_back(a);
        othmat[a].push_back(b);
    }
    int val=3e5;
    for(int i=1;i<=n;i++)dist[i]=val;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>path[i];
    }
    dist[path[k-1]]=0;
    queue<int> q;
    q.push(path[k-1]);
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(int x:matrix[cur]){
            if(dist[x]>dist[cur]+1){
                dist[x]=dist[cur]+1;
                q.push(x);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int x:othmat[i]){
            vals[i][dist[x]]++;
        }
    }
    int mi=0,ma=0;
    for(int i=0;i<k-1;i++){
        if(dist[path[i]]==dist[path[i+1]]+1){
            if(vals[path[i]][dist[path[i+1]]]>1)ma++;
        }
        else{
            mi++,ma++;
        }
    }
    printf("%d %d\n",mi,ma);
    return 0;
}