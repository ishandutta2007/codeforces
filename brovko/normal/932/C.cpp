#include <bits/stdc++.h>
//#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    int k=0;
    while(n%b && n>=0)
    {
        n-=a;
        k++;
    }

    if(n<0)
        cout << -1;
    else
    {
        int x=1;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<a-1;j++)
            {
                cout << x+1 << ' ';
                x++;
            }

            cout << x-a+1 << ' ';
            x++;
        }

        a=b;
        k=n/b;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<a-1;j++)
                {
                    cout << x+1 << ' ';
                    x++;
                }

            cout << x-a+1 << ' ';
            x++;
        }
    }
}