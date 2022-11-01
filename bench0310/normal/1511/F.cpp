#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;

const int K=26;

struct Vertex
{
    char c;
    int p;
    array<int,K> trie;
    array<int,K> go;
    int link;
    bool leaf;
    Vertex(char nc='$',int np=-1)
    {
        c=nc;
        p=np;
        trie.fill(-1);
        go.fill(-1);
        link=-1;
        leaf=0;
    }
};

vector<Vertex> ac(1);

void add(string s)
{
    int a=0;
    for(char t:s)
    {
        int c=(t-'a');
        if(ac[a].trie[c]==-1)
        {
            ac.push_back(Vertex(t,a));
            ac[a].trie[c]=(int)ac.size()-1;
        }
        a=ac[a].trie[c];
    }
    ac[a].leaf=1;
}

int go(int a,char t);

int get_link(int a)
{
    if(ac[a].link==-1)
    {
        if(a==0||ac[a].p==0) ac[a].link=0;
        else ac[a].link=go(get_link(ac[a].p),ac[a].c);
    }
    return ac[a].link;
}

int go(int a,char t)
{
    int c=(t-'a');
    if(ac[a].go[c]==-1)
    {
        if(ac[a].trie[c]!=-1) ac[a].go[c]=ac[a].trie[c];
        else ac[a].go[c]=(a==0?0:go(get_link(a),t));
    }
    return ac[a].go[c];
}

int D;
const ll mod=998244353;

mat id()
{
    mat a(D,vector<ll>(D,0));
    for(int i=0;i<D;i++) a[i][i]=1;
    return a;
}

mat operator*(const mat &a,const mat &b)
{
    mat c(D,vector<ll>(D,0));
    for(int i=0;i<D;i++) for(int j=0;j<D;j++) for(int k=0;k<D;k++) c[i][k]=(c[i][k]+a[i][j]*b[j][k])%mod;
    return c;
}

mat fpow(mat b,int e)
{
    mat res=id();
    while(e)
    {
        if(e&1) res=res*b;
        b=b*b;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        add(s);
    }
    int sz=(int)ac.size()-1;
    vector<array<int,2>> opt;
    map<array<int,2>,int> rev;
    for(int i=0;i<=sz;i++)
    {
        opt.push_back({i,i});
        int j=i;
        while(j!=0)
        {
            j=get_link(j);
            opt.push_back({min(i,j),max(i,j)});
        }
    }
    D=opt.size();
    for(int i=0;i<D;i++) rev[opt[i]]=i;
    mat a(D,vector<ll>(D,0));
    for(int now=0;now<D;now++)
    {
        auto [i,j]=opt[now];
        for(int c=0;c<26;c++)
        {
            if(ac[i].trie[c]==-1||ac[j].trie[c]==-1) continue;
            int ti=ac[i].trie[c];
            int tj=ac[j].trie[c];
            for(int x=0;x<=ac[ti].leaf;x++)
            {
                for(int y=0;y<=ac[tj].leaf;y++)
                {
                    int ni=(x==0?ti:0);
                    int nj=(y==0?tj:0);
                    int nxt=rev[{min(ni,nj),max(ni,nj)}];
                    a[nxt][now]++;
                }
            }
        }
    }
    cout << fpow(a,m)[0][0] << "\n";
    return 0;
}