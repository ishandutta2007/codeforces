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
        vector<int> v[n+1];
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if((int)v[a].size()<k) v[a].push_back(i);
        }
        vector<int> u;
        for(int i=1;i<=n;i++) for(int j:v[i]) u.push_back(j);
        while(u.size()%k) u.pop_back();
        vector<int> c(n+1,0);
        int x=1;
        for(int j:u)
        {
            c[j]=x;
            x++;
            if(x==k+1) x=1;
        }
        for(int i=1;i<=n;i++) cout << c[i] << " \n"[i==n];
    }
    return 0;
}