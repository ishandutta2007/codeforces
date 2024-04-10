#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n, a, b;
char c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for(int i=0;i<n;i++)
        cin >> c[i];
    c[n]='*';
    n++;

    int k=0;
    int ans=0;
    for(int i=0;i<n;i++)
        {
            if(c[i]=='.')
                k++;
            else
            {
                int x=0;
                int y=0;
                if(a>b)
                    {
                        x=min(a, k-k/2);
                        y=min(b, k/2);
                    }
                else
                {
                    x=min(a, k/2);
                    y=min(b, k-k/2);
                }

                ans+=x+y;
                a-=x;
                b-=y;
                k=0;
            }
        }
    cout << ans;
}