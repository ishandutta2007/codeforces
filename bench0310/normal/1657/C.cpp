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
        int c=0,l=0;
        while(l+1<n)
        {
            if(s[l]=='(')
            {
                c++;
                l+=2;
                continue;
            }
            int r=l+1;
            while(r<n&&s[r]=='(') r++;
            if(r==n) break;
            c++;
            l=r+1;
        }
        cout << c << " " << n-l << "\n";
    }
    return 0;
}