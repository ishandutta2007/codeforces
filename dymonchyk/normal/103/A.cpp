#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
//#include <complex>
#include <set>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    ll a[102]={0},dp[102]={0};
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    dp[0]=a[0];
    for(int i=1;i<n;i++)
        dp[i]=dp[i-1]+1LL*(i+1)*(a[i]-1)+1;
    cout << dp[n-1] << endl;
    return 0;
}