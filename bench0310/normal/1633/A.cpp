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
        string n;
        cin >> n;
        pair<int,string> res={3,""};
        for(int i=14;i<=999;i+=7)
        {
            string m=to_string(i);
            if(n.size()!=m.size()) continue;
            int c=0;
            for(int j=0;j<(int)n.size();j++) c+=(n[j]!=m[j]);
            res=min(res,{c,m});
        }
        cout << res.second << "\n";
    }
    return 0;
}