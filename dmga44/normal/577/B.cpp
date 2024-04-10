#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 1005

int f[MAXN],mk[MAXN],mk1[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,m,a;
    int sum=0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        f[a%m]++;
    }

    for(int i=0;i<m;i++)
    {
        if(f[i])
        {
            for(int u=0;u<m;u++)
                if(mk[u])
                    for(int j=1;j<=f[i];j++)
                    {
                        if(!mk[(u+(i*j))%m])
                            mk1[(u+(i*j))%m]=1;
                        else
                            break;
                    }
            for(int j=0;j<m;j++)
                if(mk1[j])
                {
                    mk[j]=1;
                    mk1[j]=0;
                }
            for(int j=1;j<=f[i];j++)
                mk[(i*j)%m]=1;
        }
        if(mk[0]==1)
        {
            db("YES")
            return 0;
        }
    }
    db("NO")
    return 0;
}