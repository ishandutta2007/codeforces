#include <bits/stdc++.h>
#define int long long

using namespace std;
int test, n, m, a[100005], b[100005], c[100005], Max, d[100005], t;

int32_t main()
{
    cin >> test;
    while(test--)
    {
        t=0;
        Max=0;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            {
                cin >> a[i];
                c[a[i]]=i;
            }
        for(int i=0;i<m;i++)
            cin >> b[i];
        for(int i=0;i<m;i++)
        {
            if(c[b[i]]>Max)
            {
                Max=c[b[i]];
                d[i]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(d[i]==0)
                t++;
                else t+=2*(c[b[i]]-i)+1;
        }
        cout << t << endl;
        for(int i=0;i<=n;i++)
        {
            d[i]=0;
            c[i]=0;
        }
    }
    return 0;
}