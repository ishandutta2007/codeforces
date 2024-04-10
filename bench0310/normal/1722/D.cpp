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
        ll c=0;
        for(int i=1;i<=n;i++)
        {
            int p=0;
            if(s[i]=='L') p=i-1;
            else p=n-i;
            c+=p;
            v.push_back(n-1-2*p);
        }
        ranges::sort(v,greater<>());
        for(int i=1;i<=n;i++)
        {
            c+=max(0,v[i-1]);
            cout << c << " \n"[i==n];
        }
    }
    return 0;
}