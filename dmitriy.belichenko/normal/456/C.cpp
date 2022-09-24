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
unsigned long long dp[1000005];

unsigned long long a[1000005];


int main()
{
    
    
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    
    for(int i = 0;i < n; i++)
    {
        long long x ;
        cin >> x;
        a[x]++;
    }
    dp[1] = a[1];
    unsigned long long ans = 0;
    for(int i = 2 ; i <= 100000; i++)
    {
        dp[i] = (max(dp[ i - 2] + a[i] * i , dp[i - 1]) );
        ans = max(dp[i] , ans);
    }
    cout << ans<< endl;
}