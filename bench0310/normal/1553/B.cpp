#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        int n=s.size();
        int m=t.size();
        bool res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sz=j-i+1;
                if(sz>m) continue;
                string x=s.substr(i,sz);
                if(j<m-sz) continue;
                string y=s.substr(j-(m-sz),m-sz);
                reverse(y.begin(),y.end());
                res|=(x+y==t);
            }
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}