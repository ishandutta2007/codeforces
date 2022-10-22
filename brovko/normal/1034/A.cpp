#include <bits/stdc++.h>

using namespace std;

int n, a[300005], lp[15000005];

vector <int> g[15000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=15000005;

    for(int i=2;i*i<=N;i++)
        if(lp[i]==0)
        for(int j=i*i;j<N;j+=i)
            if(lp[j]==0)
            lp[j]=i;

    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];

            while(lp[a[i]])
            {
                int j=lp[a[i]];
                int k=0;
                while(a[i]%j==0)
                {
                    a[i]/=j;
                    k++;
                }
                g[j].push_back(k);
            }
            if(a[i]>1)
                g[a[i]].push_back(1);
        }

    for(int i=0;i<15000005;i++)
        sort(g[i].begin(), g[i].end());

    int Max=0;
    for(int i=0;i<15000005;i++)
        if(g[i].size())
    {
        int x=0;
        if(g[i].size()==n)
            x=g[i][0];
        int j=0;
        while(j<n && g[i][j]==x)
            j++;
        Max=max(Max, (int)g[i].size()-j);
    }
    if(Max)
        cout << n-Max;
    else cout << -1;
}