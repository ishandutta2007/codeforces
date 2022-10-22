#include <bits/stdc++.h>
#define int long long

using namespace std;

string s;
int q, l, r, n, L[200005], c[128], k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n=s.size();
    for(int r=0;r<n;r++)
    {
        if(c[s[r]]==0)
            k++;
        c[s[r]]++;

        while(k>=3)
        {
            if(c[s[l]]==1)
                k--;
            c[s[l]]--;
            l++;
        }
        L[r]=l-1;
    }

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        l--;
        r--;
        if(r==l || s[r]!=s[l] || l<=L[r])
            cout << "Yes\n";
        else cout << "No\n";
    }
}