#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
long long  arr[1005][1005];
long long  cnt = 0;
set<long long> st;
long long sm = 0 , ans = 0;
int a[100005];
int n, s;
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
   long long sum = 0;
    for (int i = 0; i < mid; ++i)
    {
        sum += *st.begin();
        st.erase(st.begin());
    }
    return sum;
}
long long calc(int mid)
{
  long long  sum = 0;
    
    for (int i = 0; i < n; ++i)
    {
        if(!i) st.clear();
        st.insert( (long long)(a[i] + mid*(i + 1LL)));
    }
    sum = 0;
    for (int i = 0; i < mid; ++i)
    {
        sum += *(st.begin());
        if(i != n - 1)
            st.erase(st.begin());
    }
    return sum;
}
int search()
{
    int l = 0;
    int r = n + 1;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if ( calc(mid) - s <= 0  )
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}







bool recalc(long long mid)
{
  long long  sum = 0;
    vector<long long> v(n);
    for (int i=0; i<n; i++)
    {
        v[i]=(long long) a[i] + mid * (i+1LL);
    }
    sort(v.begin(), v.end());
    for (int i=0; i< mid; i++)
    {
        sum+=v[i];
    }
    if (sum <= s)
    {
        sm = sum;
        ans = mid;
        return true;
    }
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i=0; i< n; i++)
    {
        cin>>a[i];
    }
    long long l = 0, r = n;
    long long mid = 0;
    while (l - r < 0)
    {
        mid =(l + r + 1 ) >> 1;
        if (recalc(mid ))
        {
            l= mid;
        }
        else
        {
            r = mid;
            r--;
        }
       
    }
    calc(ans);
    cout<<ans<<" "<<sm << "\n";
}