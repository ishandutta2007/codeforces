#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int K=9;

struct Vertex
{
    char c;
    int p;
    array<int,K> trie;
    array<int,K> go;
    int link;
    bool leaf;
    bool bad;
    Vertex(char nc='$',int np=-1):c(nc),p(np)
    {
        trie.fill(-1);
        go.fill(-1);
        link=-1;
        leaf=bad=0;
    };
};

vector<Vertex> ac(1);

void add(string s)
{
    int now=0;
    for(char t:s)
    {
        int c=(t-'1');
        if(ac[now].trie[c]==-1)
        {
            ac[now].trie[c]=ac.size();
            ac.push_back(Vertex(t,now));
        }
        now=ac[now].trie[c];
    }
    ac[now].leaf=1;
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
    int c=(t-'1');
    if(ac[a].go[c]==-1)
    {
        if(ac[a].trie[c]!=-1) ac[a].go[c]=ac[a].trie[c];
        else ac[a].go[c]=(a==0?0:go(get_link(a),t));
    }
    return ac[a].go[c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string now;
    vector<string> xp[21];
    auto xprime=[&](int x)->bool
    {
        int n=now.size();
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=i;j<n;j++)
            {
                if(i==0&&j==n-1) continue;
                s+=(now[j]-'0');
                if((x%s)==0) return 0;
            }
        }
        return 1;
    };
    function<void(int)> gen=[&](int s)
    {
        if(s>20) return;
        if(s>0&&xprime(s)==1) xp[s].push_back(now);
        for(int i=1;i<=9;i++)
        {
            now+=(i+'0');
            gen(s+i);
            now.pop_back();
        }
    };
    gen(0);
    string s;
    int x;
    cin >> s >> x;
    for(string t:xp[x]) add(t);
    int n=(int)ac.size()-1;
    for(int i=1;i<=n;i++)
    {
        int a=i;
        while(a>0)
        {
            ac[i].bad|=ac[a].leaf;
            a=get_link(a);
        }
    }
    const int inf=(1<<30);
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for(char c:s)
    {
        vector<int> ndp(n+1,inf);
        for(int i=0;i<=n;i++)
        {
            ndp[i]=min(ndp[i],dp[i]+1);
            int to=go(i,c);
            if(ac[to].bad==0) ndp[to]=min(ndp[to],dp[i]);
        }
        dp=ndp;
    }
    int res=s.size();
    for(int i=0;i<=n;i++) res=min(res,dp[i]);
    cout << res << "\n";
    return 0;
}