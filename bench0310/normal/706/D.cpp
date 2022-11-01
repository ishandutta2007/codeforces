#include <bits/stdc++.h>

using namespace std;

const int N=6000000;
int now=1;
vector<vector<int>> trie(N,vector<int>(2,-1));
vector<int> cnt(N,0);

void add(int x)
{
    int id=0;
    for(int i=29;i>=0;i--)
    {
        if(trie[id][(x>>i)&1]==-1) trie[id][(x>>i)&1]=now++;
        id=trie[id][(x>>i)&1];
        cnt[id]++;
    }
}

void rm(int x)
{
    int id=0;
    for(int i=29;i>=0;i--)
    {
        id=trie[id][(x>>i)&1];
        cnt[id]--;
    }
}

int solve(int x)
{
    int res=0;
    int id=0;
    for(int i=29;i>=0;i--)
    {
        if(trie[id][((x>>i)&1)^1]!=-1&&cnt[trie[id][((x>>i)&1)^1]]>0)
        {
            res+=(1<<i);
            id=trie[id][((x>>i)&1)^1];
        }
        else id=trie[id][(x>>i)&1];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    add(0);
    while(t--)
    {
        char a;
        int x;
        cin >> a >> x;
        if(a=='+') add(x);
        else if(a=='-') rm(x);
        else if(a=='?') cout << solve(x) << "\n";
    }
    return 0;
}