#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
const int M=30*N;
vector<array<int,2>> trie(M,{-1,-1});
int idx=0;
vector<int> v[M];
vector<int> val(N);

void add(int id)
{
    int a=0;
    for(int i=29;i>=0;i--)
    {
        int b=((val[id]>>i)&1);
        if(trie[a][b]==-1) trie[a][b]=(++idx);
        a=trie[a][b];
        v[a].push_back(id);
    }
}

int cnt(int a,int lim)
{
    if(a==-1) return 0;
    int i=int(v[a].size())-1;
    int c=0;
    while(c<2&&i>=0&&v[a][i]<=lim){c++;i--;}
    return c;
}

int go(int lim)
{
    int a=0;
    int res=0;
    vector<int> opt;
    for(int i=29;i>=0;i--)
    {
        if(a==-1)
        {
            res=(1<<30);
            for(int j=0;j<(int)opt.size();j++) for(int k=j+1;k<(int)opt.size();k++) res=min(res,opt[j]|opt[k]);
            return res;
        }
        int one=cnt(trie[a][0],lim);
        for(int x:opt) one+=(((x>>i)&1)==0);
        if(one>=2)
        {
            vector<int> nopt;
            for(int x:opt) if(((x>>i)&1)==0) nopt.push_back(x);
            opt=nopt;
            a=trie[a][0];
        }
        else
        {
            if(cnt(trie[a][0],lim)==1) opt.push_back(val[v[trie[a][0]].back()]);
            res^=(1<<i);
            a=trie[a][1];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> val[i];
        int q;
        cin >> q;
        vector<array<int,2>> queries[n+1];
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin >> l >> r;
            queries[l].push_back({r,i});
        }
        vector<int> res(q+1,0);
        for(int i=n;i>=1;i--)
        {
            add(i);
            for(auto [r,id]:queries[i]) res[id]=go(r);
        }
        for(int i=1;i<=q;i++) cout << res[i] << "\n";
        for(int i=0;i<=idx;i++)
        {
            trie[i]={-1,-1};
            v[i].clear();
        }
        idx=0;
    }
    return 0;
}