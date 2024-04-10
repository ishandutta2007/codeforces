#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

char str[100005];
unsigned int dp[50005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d\n",&n); gets(str);
//  n=100000;
//  for(int i=0;i<n;++i) str[i]='?';
    dp[0]=1;
    int cnt=0,n2=n/2;
    for(int i=1;i<=n2;++i) {
        if (str[i-1]=='?') {
            unsigned int add=dp[0]; dp[0]=0;
            for(int j=1;j<=i;++j) {
                dp[j-1]+=dp[j];
                swap(add,dp[j]);
            }
        } else {
            ++cnt;
            for(int j=i;j>=0;--j)
                dp[j+1]=dp[j];
            dp[0]=0;
        }
    }
    for(int i=n/2+1;i<=n;++i) {
        if (str[i-1]=='?') {
            unsigned int add=dp[0]; dp[0]=0;
            for(int j=1;j<=n2;++j) {
                dp[j-1]+=dp[j];
                swap(add,dp[j]);
            }
        } else {
            ++cnt;
            for(int j=n2;j>=0;--j)
                dp[j+1]=dp[j];
            dp[0]=0;
        }
    }
    for(int i=(n2-cnt);i>0;--i)
        dp[0]*=25;
    cout << dp[0] << endl;
//  cout << clock() << endl;
    return 0;
}