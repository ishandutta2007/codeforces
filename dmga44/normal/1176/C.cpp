#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 105

ll dp[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    cin >> n;
    int f[7];
    for(int i=0;i<7;i++)
        f[i]=0;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a==4)
            f[0]++;
        else if(a==8)
        {
            if(f[0])
            {
                f[0]--;
                f[1]++;
            }
        }
        else if(a==15)
        {
            if(f[1])
            {
                f[1]--;
                f[2]++;
            }
        }
        else if(a==16)
        {
            if(f[2])
            {
                f[2]--;
                f[3]++;
            }
        }
        else if(a==23)
        {
            if(f[3])
            {
                f[3]--;
                f[4]++;
            }
        }
        else if(a==42)
        {
            if(f[4])
            {
                f[4]--;
                f[5]++;
            }
        }
    }

    db(n-(f[5]*6))

    return 0;
}