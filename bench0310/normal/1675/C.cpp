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
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        vector<int> one(n+1,1);
        for(int i=1;i<=n;i++) one[i]=(one[i-1]&&(s[i]!='0'));
        vector<int> zero(n+2,1);
        for(int i=n;i>=1;i--) zero[i]=(zero[i+1]&&(s[i]!='1'));
        int res=0;
        for(int i=1;i<=n;i++) res+=(one[i-1]&&zero[i+1]);
        cout << res << "\n";
    }
    return 0;
}