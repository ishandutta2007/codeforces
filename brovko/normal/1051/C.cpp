#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105], b[105], ka, kb, c[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    int f=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
        if(b[a[i]]==3)
            f=1;
    }
    if(f==0)
    {
        if(n%2==0)
        {
            int k=0;
            cout << "YES\n";
            for(int i=0;i<n;i++)
                {
                    if(b[a[i]]==2)
                        cout << 'A';
                    else
                    {
                        cout << char('A'+k);
                        k=1-k;
                    }
                }
        }
        else cout << "NO";
        return 0;
    }

    int k=0;
    for(int i=0;i<n;i++)
        if(b[a[i]]==1)
            k++;
    if(k%2==0)
    {
        k=0;
        cout << "YES\n";
        for(int i=0;i<n;i++)
                {
                    if(b[a[i]]>=2)
                        cout << 'A';
                    else
                    {
                        cout << char('A'+k);
                        k=1-k;
                    }
                }
    }
    else
    {
        cout << "YES\n";
        k=0;
        f=0;
        for(int i=0;i<n;i++)
                {
                    if(b[a[i]]>=3)
                        {
                            if(f)
                                cout << char('A'+f-1);
                            else
                            {
                                cout << char('A'+k);
                                k=1-k;
                                f=k+1;
                            }
                        }
                    else if(b[a[i]]==2)
                            cout << 'A';
                    else
                    {
                        cout << char('A'+k);
                        k=1-k;
                    }
                }
    }
}