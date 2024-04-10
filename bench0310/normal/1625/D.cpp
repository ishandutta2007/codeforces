#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=30*300000+1;
vector<int> id(N,-1);
vector<array<int,2>> trie(N,{-1,-1});
int now=0;
int k;
int msb=-1;
vector<int> res;

void add(int x,int t)
{
    int a=0;
    id[0]=t;
    for(int i=29;i>=0;i--)
    {
        int b=((x>>i)&1);
        if(trie[a][b]==-1) trie[a][b]=++now;
        a=trie[a][b];
        id[a]=t;
    }
}

array<int,2> go(int a,int b,int d)
{
    if(a==-1||b==-1) return {-1,-1};
    if(d==-1) return {id[a],(a!=b?id[b]:-1)};
    int x=((k>>d)&1);
    array<int,2> zero={trie[a][0],trie[b][0]};
    array<int,2> one={trie[a][1],trie[b][1]};
    if(x==1)
    {
        for(int j=0;j<2-(a==b);j++)
        {
            array<int,2> tmp=go(zero[j],one[j^1],d-1);
            if(tmp[1]!=-1) return tmp;
        }
        return {id[a],-1};
    }
    else
    {
        for(int j=0;j<2;j++) if(zero[j]!=-1&&one[j^1]!=-1) return {id[zero[j]],id[one[j^1]]};
        for(int j=0;j<2;j++)
        {
            array<int,2> tmp=go((j==0?zero:one)[j],(j==0?zero:one)[j^1],d-1);
            if(tmp[1]!=-1) return tmp;
        }
        return {id[a],-1};
    }
}

void descend(int a,int d)
{
    if(d==msb)
    {
        array<int,2> t=go(a,a,d);
        res.push_back(t[0]);
        if(t[1]!=-1) res.push_back(t[1]);
    }
    else for(int j=0;j<2;j++) if(trie[a][j]!=-1) descend(trie[a][j],d-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> k;
    for(int i=0;i<30;i++) if(k&(1<<i)) msb=i;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        add(a,i);
    }
    if(k!=0) descend(0,29);
    else for(int i=1;i<=n;i++) res.push_back(i);
    if(res.size()>=2)
    {
        cout << res.size() << "\n";
        for(int i:res) cout << i << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}