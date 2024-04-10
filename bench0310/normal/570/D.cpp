#include <bits/stdc++.h>

using namespace std;

const int N=500005;
vector<int> v[N];
vector<int> sz(N);
vector<int> depth(N);
char s[N];
vector<pair<int,int>> queries[N]; //depth,id
vector<bool> res(N);

void _dfs(int a,int p=-1)
{
    if(p==-1) depth[a]=1;
    else depth[a]=depth[p]+1;
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        _dfs(to,a);
        sz[a]+=sz[to];
    }
}

map<int,vector<int>> dfs(int a,int p=-1)
{
    int big=-1;
    for(int to:v[a]) if((to!=p)&&(big==-1||sz[to]>sz[big])) big=to;
    map<int,vector<int>> m;
    if(big!=-1) m=dfs(big,a);
    for(int to:v[a])
    {
        if(to==p||to==big) continue;
        map<int,vector<int>> t=dfs(to,a);
        for(pair<int,vector<int>> p:t)
        {
            vector<int> t(26,0);
            if(m.find(p.first)==m.end()) m[p.first]=t;
            for(int i=0;i<26;i++) m[p.first][i]+=p.second[i];
        }
    }
    vector<int> t(26,0);
    t[s[a]-'a']++;
    m[depth[a]]=t;
    for(pair<int,int> p:queries[a])
    {
        if(m.find(p.first)==m.end()) res[p.second]=1;
        else
        {
            int cnt=0;
            for(int i=0;i<26;i++) if(m[p.first][i]&1) cnt++;
            res[p.second]=(cnt<=1);
        }
    }
    return m;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        v[i].push_back(p);
        v[p].push_back(i);
    }
    scanf("%s",s+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        queries[a].push_back({b,i});
    }
    _dfs(1);
    dfs(1);
    for(int i=1;i<=m;i++)
    {
        if(res[i]) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}