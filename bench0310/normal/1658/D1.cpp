#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2300000;
int trie[N][2];
int id=0;

void add(int x)
{
    int a=0;
    for(int i=16;i>=0;i--)
    {
        int b=((x>>i)&1);
        if(trie[a][b]==0) trie[a][b]=(++id);
        a=trie[a][b];
    }
}

int mn(int x)
{
    int y=0;
    int a=0;
    for(int i=16;i>=0;i--)
    {
        int b=((x>>i)&1);
        int c=(trie[a][b]!=0?b:1-b);
        if(b!=c) y^=(1<<i);
        a=trie[a][c];
    }
    return y;
}

int mx(int x)
{
    int y=0;
    int a=0;
    for(int i=16;i>=0;i--)
    {
        int b=((x>>i)&1);
        int c=(trie[a][1-b]!=0?1-b:b);
        if(b!=c) y^=(1<<i);
        a=trie[a][c];
    }
    return y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        vector<int> opt;
        for(int i=1;i<=r-l+1;i++)
        {
            int a;
            cin >> a;
            add(a);
            opt.push_back(a^l);
        }
        int res=-1;
        for(int x:opt)
        {
            if(mn(x)==l&&mx(x)==r) res=x;
        }
        cout << res << "\n";
        for(int i=0;i<=id;i++) trie[i][0]=trie[i][1]=0;
        id=0;
    }
    return 0;
}