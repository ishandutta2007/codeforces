#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        map<string,array<int,3>> s;
        for(int i=1;i<=n;i++)
        {
            string a;
            cin >> a;
            for(int j=0;j+1<m;j++)
            {
                s[a.substr(j,2)]={j+1,j+2,i};
                if(j+2<m) s[a.substr(j,3)]={j+1,j+3,i};
            }
        }
        string a;
        cin >> a;
        a="$"+a;
        vector<int> p(m+1,-1);
        p[0]=0;
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=3;j++)
            {
                if(i>=j&&s.contains(a.substr(i-j+1,j))&&p[i-j]!=-1) p[i]=j;
            }
        }
        if(p[m]!=-1)
        {
            int x=m;
            vector<array<int,3>> res;
            while(x>0)
            {
                int sz=p[x];
                res.push_back(s[a.substr(x-sz+1,sz)]);
                x-=sz;
            }
            ranges::reverse(res);
            cout << res.size() << "\n";
            for(auto [l,r,i]:res) cout << l << " " << r << " " << i << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}