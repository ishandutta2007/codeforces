#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N=(int) 1e5+7;
const int DIMVEC=50+7;
int n, suminit, linit[DIMVEC], rinit[DIMVEC], sol[N], l[N], r[N], dp[DIMVEC][N], pre[DIMVEC][N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n>>suminit;
        for (int i=1; i<=n; i++)
        {
                cin>>linit[i]>>rinit[i];
        }

        for (int x=1; x<N; x++)
        {
                bool ok=1;
                for (int i=1; i<=n; i++)
                {
                        l[i]=(linit[i]-1)/x+1;
                        r[i]=rinit[i]/x;
                        if (l[i]>r[i])
                        {
                                ok=0;
                                break;
                        }
                }
                if (!ok)
                {
                        continue;
                }

                int sum=suminit/x;
                for (int i=0; i<=sum; i++)
                {
                        dp[0][i]=0;
                        pre[0][i]=1;
                }
                dp[0][0]=1;
                for (int i=1; i<=n; i++)
                {
                        for (int tot=0; tot<=sum; tot++)
                        {
                                dp[i][tot]=0;
                        }
                        for (int tot=l[i]; tot<=sum; tot++)
                        {
                                int ff=l[i], ss=min(tot, r[i]);
                                swap(ff, ss);
                                ff=tot-ff;
                                ss=tot-ss;
                                dp[i][tot]=add(pre[i-1][ss], -pre[i-1][ff-1]);
                        }
                        int cur=0;
                        for (int tot=0; tot<=sum; tot++)
                        {
                                cur=add(cur, dp[i][tot]);
                                pre[i][tot]=cur;
                        }
                }
                sol[x]=0;
                for (int tot=0; tot<=sum; tot++)
                {
                        sol[x]=add(sol[x], dp[n][tot]);
                }
        }

        for (int i=N-1; i>=1; i--)
        {
                for (int j=2*i; j<N; j+=i)
                {
                        sol[i]=add(sol[i], -sol[j]);
                }
        }
        cout<<sol[1]<<"\n";

        return 0;
}