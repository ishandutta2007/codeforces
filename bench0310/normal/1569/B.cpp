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
        int n;
        cin >> n;
        string s;
        cin >> s;
        s="$"+s;
        vector<int> v;
        for(int i=1;i<=n;i++) if(s[i]=='2') v.push_back(i);
        if(v.empty()||v.size()>=3)
        {
            vector<string> res(n+1,string(n+1,'='));
            for(int i=1;i<=n;i++) res[i][i]='X';
            auto win=[&](int i,int j)
            {
                res[i][j]='+';
                res[j][i]='-';
            };
            int sz=v.size();
            for(int i=0;i<sz;i++) win(v[i],v[(i+1)%sz]);
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << res[i].substr(1,n) << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}