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
        string s;
        cin >> n >> s;
        int c=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                v.push_back(i-c);
                c++;
            }
        }
        sort(v.begin(),v.end());
        ll res=0;
        int m=v.size();
        for(int i=0;i<m;i++) res+=abs(v[i]-v[m/2]);
        cout << res << "\n";
    }
    return 0;
}