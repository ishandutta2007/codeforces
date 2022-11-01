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
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int mn=0;
        int l=0;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&s[r+1]==s[l]) r++;
            mn++;
            l=r+1;
        }
        mn=(mn+2)/2;
        int mx=n;
        cout << a*n+max(mn*b,mx*b) << "\n";
    }
    return 0;
}