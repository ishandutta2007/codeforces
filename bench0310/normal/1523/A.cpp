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
        string s;
        cin >> s;
        int l=0;
        while(l<n)
        {
            if(s[l]=='1')
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<n&&s[r+1]=='0') r++;
            if(l==0&&r==n-1) break;
            else if(l==0)
            {
                for(int i=0;i<m&&r-i>=0;i++) s[r-i]='1';
            }
            else if(r==n-1)
            {
                for(int i=0;i<m&&l+i<n;i++) s[l+i]='1';
            }
            else
            {
                for(int i=0;i<m&&l+i<r-i;i++) s[l+i]=s[r-i]='1';
            }
            l=r+1;
        }
        cout << s << "\n";
    }
    return 0;
}