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
        vector<int> p;
        for(int i=0;i<n;i++) if(s[i]=='0') p.push_back(i);
        int res=0;
        for(int i=0;i+1<(int)p.size();i++) res+=max(0,3-(p[i+1]-p[i]));
        cout << res << "\n";
    }
    return 0;
}