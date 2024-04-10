#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    vector<array<int,26>> trie(1);
    vector<int> opt(1,0);
    trie[0].fill(-1);
    int idx=0;
    auto add=[&](string t,int val)
    {
        int a=0;
        for(char c:t)
        {
            if(trie[a][c-'a']==-1)
            {
                trie[a][c-'a']=(++idx);
                trie.push_back(array<int,26>{});
                trie.back().fill(-1);
                opt.push_back(0);
            }
            a=trie[a][c-'a'];
            opt[a]=val;
        }
    };
    for(int i=0;i<n;i++)
    {
        if(i==0||z[n-i]==i) add(s.substr(i,10),i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        string t;
        cin >> t;
        int m=t.size();
        auto pos=[&](int p)->char
        {
            if(p<n) return s[p];
            else return t[p-n];
        };
        int a=0;
        for(int i=0;i<m;i++)
        {
            int res=0;
            //no s
            for(int j=1;j<=i+1;j++)
            {
                bool ok=1;
                for(int k=0;k<j;k++) ok&=(pos(k)==pos(n+i-j+1+k));
                if(ok) res=max(res,j);
            }
            //middle s
            if(a!=-1) a=trie[a][t[i]-'a'];
            if(a!=-1) res=max(res,opt[a]+i+1);
            //both s and t
            for(int j=0;j<i;j++)
            {
                bool ok=1;
                for(int k=0;k<i+1;k++) ok&=(pos(n+k)==pos(n+j-i+k));
                if(ok&&n+i-(n+j)<n&&z[n+i-(n+j)]==n+j-i) res=max(res,n+j+1);
            }
            cout << res << " \n"[i==m-1];
        }
    }
    return 0;
}