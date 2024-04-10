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
        vector<int> p(n+1,0);
        vector<int> q(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            q[p[i]]=i;
        }
        int x=1;
        for(int i=n;i>=1;i--) if(p[i]!=i) x=i;
        reverse(p.begin()+x,p.begin()+q[x]+1);
        for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    }
    return 0;
}