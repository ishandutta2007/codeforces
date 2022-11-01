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
        string a,b;
        cin >> a >> b;
        int l=0,r=n-1;
        vector<int> res;
        for(int i=n-1;i>=0;i--)
        {
            if(((n-1-i)%2)==0)
            {
                if(a[l]==b[i]) res.push_back(1);
                l++;
            }
            else
            {
                if(a[r]!=b[i]) res.push_back(1);
                r--;
            }
            res.push_back(i+1);
        }
        cout << res.size();
        for(int x:res) cout << " " << x;
        cout << "\n";
    }
    return 0;
}