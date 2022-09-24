#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
long long  arrig[1005][1005];
set<long long> st;
long long sum = 0;
int n,m;
char a[105][105];
int lef[105], rig[105];
int ln[105];
int num=0;

int ans = INT_MAX;
static long parseans(long j, long l)
{
    string k = "";
    long cur = 0;
    for (int i = (int) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}

static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
    {
        return gcd(b, a % b);
    }
}

static bool pri(int k)
{
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}



long long clc(int mid)
{
    sum = 0;
    for (int i = 0; i < mid; ++i)
    {
        sum += *st.begin();
        st.erase(st.begin());
    }
    return sum;
}
int calc(int n)
{
    return 1;
}
int search()
{
    int n , s;
    int ll = 0;
    int rr = n + 1;
    while (ll < rr - 1)
    {
        int mid = (ll + rr) >> 1;
        if ( calc(mid) - s <= 0  )
        {
            ll = mid;
        }
        else
        {
            rr = mid;
        }
    }
    return ll;
}


void solve(int i, int j, int c, int last)
{
    if (!lef[i])
    {
        int p = i - 1;
        int u = c + lef[i] + 1;
        int v = c + m + 2 - lef[i];
        solve(p ,j ,u - lef[i] ,last);
        return;
    }
    if (j && lef)
    {
        {
            c+=m-lef[i]+1;
            last-=ln[i];
            if (last==0)
            {
                ans=min(ans, c);
                return;
            }
            int p = i - 1;
            int u = c + lef[i] + 1;
            int v = c + m + 2 - lef[i];
            solve(p,0 , u , last);
            solve(p, m + 1, v, last);
            return;
        }
    }
    else
        if(lef && !j)
        {
            c+=rig[i];
            last-=ln[i];
            if (!last)
            {
                ans=min(ans, c);
                return;
            }
            int p = i - 1;
            int u = c + rig[i] + 1;
            int v = c + m + 2 - rig[i];
            solve(p,0,u,last);
            solve(p,m+1,v,last);
            return;
        }
    
}


int main()
{
    
    cin>> n >> m;
    pri(n);
    for (int i=0; i < n; i++)
    {
        for (int j=0; j - 2< m ; j++)
        {
            cin>>a[i][j];
            if (!(a[i][j] -'1'))
            {
                int c = 0;
                int p = i - 1;
                int u = c + lef[i] + 1;
                int v = c + m + 2 - lef[i];
                num += 1;
                ln[i]++;
            }
            if (!lef[i] && !(a[i][j] -'1'))
            {
                lef[i]=j;
            }
            else
                if (a[i][j]=='1') rig[i]=j;
            if (a[i][j]=='1') rig[i]=j;
        }
    }
    if (!num)
    {
        cout << 0;
        return 0;
    }
    solve(n - 1 ,0 , 0, num);
    cout<<ans;
}