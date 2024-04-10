#include <bits/stdc++.h>

using namespace std;

const int N=1000+7;
int n, l[N], r[N], a[N], y=0;

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
                cin>>l[i];
        for (int i=1; i<=n; i++)
                cin>>r[i];
        for (int i=1; i<=n; i++)
                a[i]=-1;
        int y=n+1;
        while (1)
        {
                y--;
                int unknown=0;
                for (int i=1; i<=n; i++)
                        unknown+=(a[i]==-1);
                if (unknown==0)
                        break;
                int minsum=(int) 1e9;
                for (int i=1; i<=n; i++)
                        if (a[i]==-1)
                                minsum=min(minsum, l[i]+r[i]);
               /// cout<<"minsum = "<<minsum<<"\n";
                for (int i=1; i<=n; i++)
                        if (a[i]==-1 && l[i]+r[i]==minsum)
                        {
                                int bef=0, aft=0;
                                for (int j=1; j<=n; j++)
                                        if (a[j]!=-1)
                                        {
                                                bef+=(j<i);
                                                aft+=(j>i);
                                        }
                                if (l[i]!=bef || r[i]!=aft)
                                {
                                        cout<<"NO\n";
                                        return 0;
                                }
                        }
                for (int i=1; i<=n; i++)
                        if (a[i]==-1 && l[i]+r[i]==minsum)
                                a[i]=y;
        }
        cout<<"YES\n";
        for (int i=1; i<=n; i++)
                cout<<a[i]<<" ";
        cout<<"\n";
        return 0;
}
/**

alea care au cea mai mica valoare au 0 la stanga si 0 la dreapta

**/