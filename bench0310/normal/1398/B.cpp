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
        string s;
        cin >> s;
        int n=s.size();
        int l=0;
        vector<int> v;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&s[r+1]==s[l]) r++;
            if(s[l]=='1') v.push_back(r-l+1);
            l=r+1;
        }
        sort(v.begin(),v.end(),greater<int>());
        int res=0;
        for(int i=0;i<(int)v.size();i+=2) res+=v[i];
        cout << res << "\n";
    }
    return 0;
}