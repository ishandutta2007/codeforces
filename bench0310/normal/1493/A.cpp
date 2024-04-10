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
        vector<int> a(k+1,0);
        a[0]=1;
        vector<int> res;
        for(int i=k;i>=1;i--)
        {
            if(a[k-i]==0)
            {
                res.push_back(i);
                for(int j=k-i;j>=0;j--) if(a[j]==1) a[j+i]=1;
            }
        }
        for(int i=k+1;i<=n;i++) res.push_back(i);
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}