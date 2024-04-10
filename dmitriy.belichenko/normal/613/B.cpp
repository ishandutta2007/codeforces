#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<set>
#include<map>
#include<iomanip>
#include<string>
#include<iostream>
#include<math.h>
#define count count1557
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


int n, A, cf, cm;
long long m;
long long a[100005];
long long b[100005];
long long ord[100005];
long long sum[100005];
bool comp(const int &i, const int &j) {
    return a[i] < a[j];
}



int main()
{
   

    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> cf >>cm >> m;
       for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
        ord[i] = i;
    }
    sort(ord , ord+n , comp);
     sort(a , a+n);
    for (int i = 0; i < n; ++i)
    {
        sum[i + 1] = sum[i] + a[i];
    }
    long long ans = -1, ansi = -1, ansm = -1;
    for (int i = 0, j = 0; i <= n; ++i)
    {
      
        long long cost = 0;
        long long tmp = 0;
        cost = (long long)A * (n - i) - (sum[n] - sum[i]);
        if (cost > m)
        {
            continue;
        }
        tmp += (n - i) * cf;
        long long left = m - cost;
        while (j < i && (long long)j * a[j] - sum[j] <= left)
        {
            j++;
        }
        long long mins = 0;
        if (j > 0)
        {
            mins = min((long long)A, (left + sum[j]) / j);
        }
        else
        {
            mins = A;
        }
        tmp += (long long)mins * cm;
        if (tmp > ans) {
            ans = tmp;
            ansi = i;
            ansm = mins;
        }
    }
    cout << ans << endl;
    long long cost = 0, mins = A, maxs = 0;
    for (int i = 0; i < n; ++i)
    {
        long long del = 0, u = b[ord[i]];
        if (i >= ansi)
        {
            del = A - u;
        }
        else
        {
            del = max(0ll, ansm - u);
        }
        b[ord[i]] += del;
        cost += del;
        mins = min(mins, (long long)b[ord[i]]);
        maxs += b[ord[i]] == A;
    }
    for (int i = 0; i < n; ++i) cout << b[i] << " ";
        return 0;
}