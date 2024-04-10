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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> h(n+1,0);
        h[0]=1;
        int now=0;
        int c=1;
        int l=2;
        while(l<=n)
        {
            int r=l;
            while(r+1<=n&&a[r]<=a[r+1]) r++;
            h[now+1]+=(r-l+1);
            l=r+1;
            c--;
            if(l<=n&&c==0) c=h[++now];
        }
        cout << now+1 << "\n";
    }
    return 0;
}