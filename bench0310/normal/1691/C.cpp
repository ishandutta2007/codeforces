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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="$"+s;
        int r=n;
        while(r>=1&&s[r]=='0') r--;
        int l=1;
        while(l<=n&&s[l]=='0') l++;
        if(l!=n+1)
        {
            bool mv=0;
            if(n-r<=k)
            {
                swap(s[r],s[n]);
                k-=(n-r);
                mv=1;
            }
            if(l-1<=k&&(l!=r||!mv)) swap(s[1],s[l]);
        }
        int res=0;
        for(int i=1;i<n;i++) res+=stoi(s.substr(i,2));
        cout << res << "\n";
    }
    return 0;
}