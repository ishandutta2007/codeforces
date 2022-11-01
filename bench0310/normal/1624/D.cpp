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
        vector<int> c(26,0);
        string s;
        cin >> s;
        for(char a:s) c[a-'a']++;
        int mx=0;
        for(int x:c) mx+=(x/2);
        int l=0,r=n/k+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(k*(m/2)<=mx) l=m;
            else r=m;
        }
        cout << l << "\n";
    }
    return 0;
}