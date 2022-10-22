#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int sum[MAXN][2],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        sum[i+1][0]=sum[i][0];
        sum[i+1][1]=sum[i][1];
        cin >> a[i];
        sum[i+1][i&1]+=a[i];
    }

    int res=0;
    for(int i=0;i<n;i++)
    {
        int s0=sum[i][0];
        int s1=sum[i][1];
        s0+=sum[n][1]-sum[i+1][1];
        s1+=sum[n][0]-sum[i+1][0];
        if(s0==s1)
            res++;
    }
    db(res)

    return 0;
}