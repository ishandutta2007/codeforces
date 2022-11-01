#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<array<int,3>> trie(30*N,{-1,-1,0}); //0,1,c
int tidx=1;
vector<array<ll,2>> cnt(30,{0,0}); //0,1

void add(int a)
{
    int now=0;
    for(int i=29;i>=0;i--)
    {
        int b=((a>>i)&1);
        if(trie[now][b]==-1) trie[now][b]=tidx++;
        if(trie[now][1-b]!=-1) cnt[i][1-b]+=trie[trie[now][1-b]][2];
        now=trie[now][b];
        trie[now][2]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        add(a);
    }
    ll res=0;
    int x=0;
    for(int i=0;i<=29;i++)
    {
        if(cnt[i][0]<cnt[i][1])
        {
            x^=(1<<i);
            swap(cnt[i][0],cnt[i][1]);
        }
        res+=cnt[i][1];
    }
    cout << res << " " << x << "\n";
    return 0;
}