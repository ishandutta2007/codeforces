#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto chmax=[&](int &a,int b){a=max(a,b);};
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<array<int,2>> trie={{-1,-1}};
        vector<array<int,4>> opt={{0,0,0,0}};
        int res=0;
        int tidx=0;
        auto add=[&](int a,int i,int d)
        {
            int x=0;
            for(int j=29;j>=0;j--)
            {
                int ba=(a>>j)&1;
                int bi=(i>>j)&1;
                chmax(opt[x][2*ba+bi],d);
                if(trie[x][ba^bi]==-1)
                {
                    trie[x][ba^bi]=(++tidx);
                    trie.push_back({-1,-1});
                    opt.push_back({0,0,0,0});
                }
                x=trie[x][ba^bi];
            }
        };
        auto qry=[&](int a,int i)->int
        {
            int dp=0;
            int x=0;
            for(int j=29;j>=0;j--)
            {
                int ba=(a>>j)&1;
                int bi=(i>>j)&1;
                chmax(dp,opt[x][2*bi+1-ba]);
                x=trie[x][ba^bi];
                if(x==-1) break;
            }
            return dp;
        };
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            int d=qry(a,i)+1;
            chmax(res,d);
            add(a,i,d);
        }
        cout << res << "\n";
    }
    return 0;
}