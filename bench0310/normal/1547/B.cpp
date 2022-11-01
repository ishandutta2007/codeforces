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
        string s;
        cin >> s;
        int n=s.size();
        string t=s;
        sort(t.begin(),t.end());
        cout << ([&]()->bool
        {
            for(int i=0;i<n;i++) if(t[i]!=('a'+i)) return 0;
            int x=s.find('a');
            for(int i=x-1;i>=0;i--) if(s[i]<s[i+1]) return 0;
            for(int i=x+1;i<n;i++) if(s[i]<s[i-1]) return 0;
            return 1;
        }()?"YES\n":"NO\n");
    }
    return 0;
}