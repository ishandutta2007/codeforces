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
        vector<int> v;
        for(int i=0;i<n;i++) if(s[i]=='*') v.push_back(i);
        int m=v.size();
        int res=1;
        int l=0;
        while(l<m-1)
        {
            int r=l;
            while(r+1<m&&v[r+1]-v[l]<=k) r++;
            res++;
            l=r;
        }
        cout << res << "\n";
    }
    return 0;
}