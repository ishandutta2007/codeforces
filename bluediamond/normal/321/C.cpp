#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n;
vector<int>g[N];
bool block[N];
bool viz[N];

int sub[N];

int centeroid;

void build(int nod,int dad)
{
    sub[nod]=1;
    for(auto &nou:g[nod])
    {
        if(nou==dad) continue;
        if(block[nou]) continue;
        build(nou,nod);
        sub[nod]+=sub[nou];
    }
}

int go,sz;

void fcen(int nod,int dad)
{
    bool ok=1;
    int up=sub[go]-sub[nod];
    if(up>sz/2) ok=0;
    for(auto &nou:g[nod])
    {
        if(nou==dad) continue;
        if(block[nou]) continue;
        fcen(nou,nod);
        int val=sub[nou];
        if(val>sz/2) ok=0;
    }
    if(ok==1)
    {
        centeroid=nod;
    }
}

int res[N];

void slove(int nod,int x)
{
    go=nod;
    build(nod,-1);
    sz=sub[nod];
    if(sz==1)
    {
        res[nod]=x;
        return;
    }
    fcen(nod,-1);
    int kek=centeroid;
    res[kek]=x;
    block[kek]=1;
    for(auto &nou:g[kek])
    {
        if(block[nou]==0)
        {
            slove(nou,x+1);
        }
    }
    ///cout<<centeroid<<"\n";
}

int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //  freopen("in","r",stdin); freopen("out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    slove(1,0);
    for(int i=1;i<=n;i++)
    {
            cout<<char('A'+res[i])<<" ";
            continue;
        for(auto &j:g[i])
        {
            if(j>i)
            {
                cout<<i<<char('A'+res[i])<<" "<<j<<char('A'+res[j])<<"\n";
            }
        }

    }
    cout<<"\n";
    return 0;
}
/**


**/