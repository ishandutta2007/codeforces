#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=100000;
const int INF=(int) 1e9;
bool ok[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);


        ok[0]=1;
        for (int i=0; i<N; i++)
        {
                if (ok[i]&&i+6<N) ok[i+6]=1;
                if (ok[i]&&i+8<N) ok[i+8]=1;
                if (ok[i]&&i+10<N) ok[i+10]=1;
        }
        for (int i=1000; i<N; i+=2)
        {
                assert(ok[i]);
        }

        int t;
        cin>>t;
        while (t--)
        {
                int n, sol;
                cin>>n;
                if (n%2) n++;
                if (n<N)
                {
                        while (!ok[n]) n+=2;
                }
                assert(n%2==0);
                cout<<n/2*5<<"\n";
        }
}