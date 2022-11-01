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
        auto solve=[](vector<int> a,vector<int> b)->int
        {
            int n=a.size();
            int m=b.size();
            set<int> opt(b.begin(),b.end());
            vector<int> suf(n+1,0);
            for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+(opt.find(a[i])!=opt.end());
            int res=0;
            int box=0;
            int cnt=0;
            int r=-1;
            for(int l=0;l<m;l++)
            {
                r=max(r,l-1);
                while(box<n&&a[box]<=b[l]+cnt)
                {
                    box++;
                    cnt++;
                }
                while(r+1<m&&b[r+1]<=b[l]+cnt-1) r++;
                res=max(res,r-l+1+suf[box]);
            }
            return res;
        };
        int n,m;
        cin >> n >> m;
        vector<int> a[2];
        vector<int> b[2];
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            a[x>0].push_back(abs(x));
        }
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            b[x>0].push_back(abs(x));
        }
        reverse(a[0].begin(),a[0].end());
        reverse(b[0].begin(),b[0].end());
        cout << solve(a[0],b[0])+solve(a[1],b[1]) << "\n";
    }
    return 0;
}