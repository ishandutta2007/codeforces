#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+5;
int n,m,cate;
vector<int>v[N];
bool viz[N];
int ans[2*N],cnt=0;

void dfs(int nod)
{
    viz[nod]=1;
    ans[++cnt]=nod;
    int nr=0;
    for(auto nou:v[nod])
    {
        if(viz[nou]) continue;
        nr++;
        dfs(nou);
        if(nr>0)
            ans[++cnt]=nod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>cate;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int ma=(2*n+cate-1)/cate;
    int cur=1;
    for(int poz=1;poz<=cate;poz++)
    {
        int dr=min(cnt,cur+ma-1);
        if(dr-cur+1==0)
        {
            cout<<"1 1\n";
            continue;
        }
        cout<<dr-cur+1<<" ";
        while(cur<=dr)
        {
            cout<<ans[cur]<<" ";
            cur++;
        }
        cout<<"\n";
    }
    return 0;
}
/**
**/