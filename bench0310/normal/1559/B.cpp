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
        int l=0;
        while(l<n)
        {
            if(s[l]!='?')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&s[r+1]=='?') r++;
            int x=0;
            if(l>0) x=(s[l-1]=='B');
            else if(r<n-1) x=((s[r+1]=='B')^((r-l)&1));
            for(int i=l;i<=r;i++)
            {
                s[i]="BR"[x];
                x^=1;
            }
            l=r+1;
        }
        cout << s << "\n";
    }
    return 0;
}