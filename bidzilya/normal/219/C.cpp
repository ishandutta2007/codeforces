#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

int n,k;
int dp[500000][26],p[500000][26];
string s;

int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i=0;i<k;i++)dp[0][i]=1;
    dp[0][s[0]-'A']=0;
    for (int i=1;i<n;i++)
    {
        for (int pr=0;pr<k;pr++)
            dp[i][pr]=MAX_INT;
        int t = s[i]-'A';
        for (int pr=0;pr<k;pr++)
            for (int nx=0;nx<k;nx++)
                if (pr!=nx)
                {
                           int res = dp[i-1][pr]+(t!=nx);
                           if (res<dp[i][nx])
                           {
                                             dp[i][nx] = res;
                                             p[i][nx] = pr;
                           }
                }
    }
    int ans = 0;
    for (int i=1;i<k;i++)
        if (dp[n-1][i]<dp[n-1][ans])
           ans = i;
    cout << dp[n-1][ans] << endl;
    vector<int> an;
    for (int i=n-1;i>=0;ans=p[i][ans],i--)
        an.push_back(ans);
    for (int i=an.size()-1;i>=0;i--)
        cout << (char)(an[i]+'A');
    cout << endl; 
  //  system("pause");
    return 0;
}