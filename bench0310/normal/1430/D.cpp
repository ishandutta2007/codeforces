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
        string s;
        cin >> n >> s;
        s="$"+s;
        vector<int> a;
        int l=1;
        while(l<=n)
        {
            int r=l;
            while(r+1<=n&&s[r+1]==s[l]) r++;
            a.push_back(r-l+1);
            l=r+1;
        }
        int m=a.size();
        int now=0;
        int idx=0;
        int res=0;
        while(now<m)
        {
            idx=max(idx,now);
            while(idx<m&&a[idx]==1) idx++;
            if(idx==m)
            {
                res+=(m-now+1)/2;
                break;
            }
            a[idx]--;
            res++;
            now++;
        }
        cout << res << "\n";
    }
    return 0;
}