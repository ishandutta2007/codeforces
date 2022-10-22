#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;
const int MOD=998244353;

int n, k, a[200005], dp[200005];
vector <int> v1, v2;

int add(int x, int y)
{
    return (x+y)%MOD;
}

int mul(int x, int y)
{
    return x*y%MOD;
}

int binpow(int x, int y)
{
    if(y==0)
        return 1;
    if(y%2)
        return mul(x, binpow(x, y-1));
    int z=binpow(x, y/2);
    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    dp[1]=k-1;
    dp[2]=mul(k-1, k-2);
    for(int i=3;i<200005;i++)
        dp[i]=add(mul(k-2, binpow(k-1, i-1)), dp[i-2]);

    for(int i=0;i<n;i+=2)
        v1.push_back(a[i]);
    for(int i=1;i<n;i+=2)
        v2.push_back(a[i]);

    for(int i=0;i<n-2;i++)
        if(a[i]!=-1 && a[i]==a[i+2])
    {
        cout << 0;
        return 0;
    }

    /*for(int i=0;i<v1.size();i++)
        cout << v1[i] << ' ';
    cout << endl;*/

    int ans=1;

    int m=v1.size();
    int f=0;
    for(int i=0;i<m;i++)
        if(v1[i]!=-1)
            f=1;
    if(f==0)
        ans=mul(ans, mul(k, binpow(k-1, m-1)));
    else
    {
        int i=0;
        while(v1[i]==-1)
            i++;
        if(i)
            ans=mul(ans, binpow(k-1, i));

        while(i<m)
        {
            //cout << i << ' ' << ans << "!\n";
            int x=0;
            int y=v1[i];
            i++;
            while(i<m && v1[i]==-1)
            {
                i++;
                x++;
            }

            if(i<m && x>0)
                {
                    int c=dp[x];
                    if(v1[i]!=y)
                        c=add(c, binpow(MOD-1, x));
                    ans=mul(ans, c);
                }
            else if(x>0)
                ans=mul(ans, binpow(k-1, x));
        }
    }
    //cout << ans << endl;





    swap(v1, v2);





    m=v1.size();
    f=0;
    for(int i=0;i<m;i++)
        if(v1[i]!=-1)
            f=1;
    if(f==0)
        ans=mul(ans, mul(k, binpow(k-1, m-1)));
    else
    {
        int i=0;
        while(v1[i]==-1)
            i++;
        if(i)
            ans=mul(ans, binpow(k-1, i));

        //cout << ans << endl;

        while(i<m)
        {
            //cout << i << ' ' << ans << "!\n";
            int x=0;
            int y=v1[i];
            i++;
            while(i<m && v1[i]==-1)
            {
                i++;
                x++;
            }

            if(i<m && x>0)
                {
                    int c=dp[x];
                    if(v1[i]!=y)
                        c=add(c, binpow(MOD-1, x));
                    ans=mul(ans, c);
                }
            else if(x>0)
                ans=mul(ans, binpow(k-1, x));
        }
    }

    cout << ans;
}