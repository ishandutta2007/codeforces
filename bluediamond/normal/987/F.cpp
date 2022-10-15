#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int N=(1<<22);

int n,m;
int v[N+5];
bool gasit[N+5];
bool viz[2][N+5];

int cnt=0;

void dfs(int tip,int nod){ ///tip - 0 = array ; tip - 1 = not array
    if(viz[tip][nod]==1)
        return;
    viz[tip][nod]=1;
    if(tip==0){
        dfs(1,nod);
        return;
    }
    for(int bt=0;bt<n;bt++){
        if(nod&(1<<bt))
            continue;
        int val=nod+(1<<bt);
        dfs(1,val);
    }
    int inv=(1<<n)-1-nod;
    if(gasit[inv]==0)
        return;
    dfs(0,inv);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i];
        gasit[v[i]]=1;
    }
    for(int i=1;i<=m;i++){
        if(viz[0][v[i]]==1)
            continue;
        dfs(0,v[i]);
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
/**

**/