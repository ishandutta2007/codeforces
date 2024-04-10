#include <bits/stdc++.h>
#define int long long
#define y1 iowfhjeofie
#define id long double

using namespace std;

int n, a[5005], ans[5005], b[5005], k[5005];
map <vector <int>, int> m;
vector <int> v[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]<0)
            {
                a[i]=-a[i];
                v[i].push_back(-1);
            }

            for(int j=2;j*j<=a[i];j++)
                {
                    int k=0;
                    while(a[i]%j==0)
                    {
                        a[i]/=j;
                        k++;
                    }
                    if(k%2)
                        v[i].push_back(j);
                }
            if(a[i]!=1)
                v[i].push_back(a[i]);
        }

    int y=1;
    for(int i=0;i<n;i++)
    {
        if(m[v[i]]==0)
        {
            m[v[i]]=y;
            b[i]=y;
            y++;
        }
        else b[i]=m[v[i]];
    }

    for(int i=0;i<n;i++)
    if(a[i]==0)
        b[i]=5001;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5005;j++)
            k[j]=0;
        int x=0;

        for(int j=i;j<n;j++)
        {
            if(a[j]!=0)
                k[b[j]]++;
            if(k[b[j]]==1 && a[j]!=0)
                x++;
            ans[max(1ll, x)]++;
        }
    }

    for(int i=1;i<=n;i++)
        cout << ans[i] << ' ';
}