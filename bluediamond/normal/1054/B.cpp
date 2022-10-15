#include <bits/stdc++.h>

using namespace std;

const int N=100000+7;
int n, a[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        int want=0;
        for (int i=1; i<=n; i++)
        {
                if (a[i]>want)
                {
                        cout<<i<<"\n";
                        return 0;
                }
                want=max(want, a[i]+1);
        }
        cout<<"-1\n";
        return 0;
}