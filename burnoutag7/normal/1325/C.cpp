#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > g[100005];
int deg[100005];
int col[100005];int colcnt;

void solve(int x){
    for(pair<int,int> &p:g[x]){
        col[p.second]=++colcnt;
    }
    for(int i=1;i<n;i++){
        if(!col[i])col[i]=++colcnt;
        printf("%d\n",col[i]-1);
    }
}

int main(){

    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        deg[a]++;
        deg[b]++;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }
    for(int i=1;i<=n;i++){
        if(deg[i]>=3){
            solve(i);
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        printf("%d\n",i-1);
    }

    return 0;
}