#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;
bool g[15][15];
map<ll,bool> dp;

void parse(vector<int> &v){
    static int f[1<<6][6],p1[6],p2[6];
    memset(f,0,sizeof(f));
    memset(p1,-1,sizeof(p1));
    memset(p2,-1,sizeof(p2));
    for(int i=0;i<v.size();i++){
        if(p1[v[i]]==-1) p1[v[i]]=i;
        else p2[v[i]]=i;
    }
    int c=n/2;
    for(int i=0;i<c;i++)
        f[1<<i][i]=g[p1[i]][p2[i]];
    for(int s=0;s<1<<c;s++)for(int i=0;i<c;i++)if(f[s][i]){
        for(int j=0;j<c;j++)if(s>>j&1^1){
            f[s|1<<j][j]|=g[p1[i]][p1[j]]&&g[p2[i]][p2[j]];
            f[s|1<<j][j]|=g[p1[i]][p2[j]]&&g[p2[i]][p1[j]];
        }
    }
    if(*max_element(f[(1<<c)-1],f[(1<<c)-1]+c)){
        ll h=0;
        for(int x:v)h=h*6+x;
        dp[h]=1;
    }
}

void prec(int c,vector<int> &v){
    int x=0;
    while(x<n&&v[x]!=-1)x++;
    if(x==n){
        parse(v);
        return;
    }
    for(int y=x+1;y<n;y++)if(v[y]==-1){
        v[x]=v[y]=c;
        prec(c+1,v);
        v[x]=v[y]=-1;
    }
}

bool dfs(vector<int> &v){
    vector<int> u(n,-1);
    int tot=0;
    for(int i=0;i<n;i++)if(u[v[i]]==-1)u[v[i]]=tot++;
    ll h=0;
    for(int c:v)h=h*6+u[c];
    if(dp.count(h))return dp[h];
    bool res=0;
    vector<int> cnt(tot);
    for(int c:v)cnt[c]++;
    for(int i=0;i<v.size();i++)if(cnt[v[i]]>2){
        int tmp=v[i];
        for(int j=i+1;j<v.size();j++)if(v[i]==v[j]){
            v[i]=v[j]=tot;
            res=dfs(v);
            v[i]=v[j]=tmp;
            if(res)break;
        }
        break;
    }
    return dp[h]=res;
}

void gen(int c,vector<int> &v){
    int x=0;
    while(x<n&&v[x]!=-1)x++;
    if(x==n){
        dfs(v);
        return;
    }
    for(int i=0;i<=c;i++){
        for(int y=x+1;y<n;y++)if(v[y]==-1){
            v[x]=v[y]=i;
            gen(c+(c==i),v);
            v[x]=v[y]=-1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a][b]=g[b][a]=1;
    }
    vector<int> v(n,-1);
    prec(0,v);
    gen(0,v);
    ll ans=0;
    vector<int> fact(1,1);
    for(int i=1;i<=k;i++)fact.emplace_back(fact.back()*i);
    for(auto [x,y]:dp)if(y){
        int c=0;
        ll t=x;
        while(t){
            c=max(c,int(t%6));
            t/=6;
        }
        if(c<k)ans+=fact[k]/fact[k-c-1];
    }
    cout<<ans<<endl;

    return 0;
}