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
        vector<int> c(3,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[a%3]++;
        }
        int res=0;
        for(int i=0;i<6;i++)
        {
            int x=max(0,c[i%3]-n/3);
            res+=x;
            c[i%3]-=x;
            c[(i+1)%3]+=x;
        }
        cout << res << "\n";
    }
    return 0;
}