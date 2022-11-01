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
        vector<int> c(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[a]++;
        }
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=c[i+1];
        sort(v.begin(),v.end(),greater<int>());
        int z=0;
        for(int i=1;i<n;i++) z+=(v[i]==v[0]);
        int x=(n-v[0])/(v[0]-1);
        while((n-v[0]-(v[0]-1)*x)<z) x--;
        cout << x << "\n";
    }
    return 0;
}