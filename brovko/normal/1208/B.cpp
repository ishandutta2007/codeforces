#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a[2005], k, b[2005], Min, f, c[2005];
map <int, int> m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    k=1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(m[a[i]])
            a[i]=m[a[i]];
        else
        {
            m[a[i]]=k;
            a[i]=k;
            k++;
        }
    }

    Min=1e9;
    int x=0;

    for(int i=0;i<n;i++)
        {
            b[a[i]]++;
            if(b[a[i]]==2)
                x++;
        }

    if(x==0)
    {
        cout << 0;
        return 0;
    }

    for(int i=0;i<n;i++)
        {
            int y=x;
            for(int j=1;j<=n;j++)
                c[j]=0;

            for(int j=i;j<n;j++)
            {
                c[a[j]]++;
                if(c[a[j]]+1==b[a[j]])
                    y--;
                if(y==0)
                    Min=min(Min, j-i+1);
            }
        }
    cout << Min;
}