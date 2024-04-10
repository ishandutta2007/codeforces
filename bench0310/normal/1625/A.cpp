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
        int n,l;
        cin >> n >> l;
        vector<int> x(n);
        for(int i=0;i<n;i++) cin >> x[i];
        int y=0;
        for(int i=0;i<l;i++)
        {
            int c=0;
            for(int a:x) c+=((a>>i)&1);
            if(c>n/2) y^=(1<<i);
        }
        cout << y << "\n";
    }
    return 0;
}