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
        p[n]=n;
        if((n%2)==0) p[n-1]=n-1;
        else
        {
            p[n-2]=1;
            p[n-1]=n-2;
        }
        vector<bool> u(n+1,0);
        for(int i=1;i<=n;i++) u[p[i]]=1;
        int x=1;
        for(int i=n;i>=1;i--) if(u[i]==0) p[x++]=i;
        for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    }
    return 0;
}