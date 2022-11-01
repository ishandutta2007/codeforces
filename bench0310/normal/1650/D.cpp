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
        vector<int> d(n+1,0);
        for(int i=n;i>=1;i--)
        {
            int x=ranges::find(a,i)-a.begin();
            if(x<i)
            {
                d[i]=x;
                rotate(a.begin()+1,a.begin()+x+1,a.begin()+i+1);
            }
        }
        for(int i=1;i<=n;i++) cout << d[i] << " \n"[i==n];
    }
    return 0;
}