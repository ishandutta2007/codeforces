#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;
#define MAX_INT (int)10e9
#define MAX_INT64 (__int64)10e18
#define eps 1e-8

#define open_ins() ifstream cin("input.txt")
#define open_outs() ofstream cout("output.txt");
#define open_outf() freopen("output.txt","w",stdout)
#define open_inf() freopen("input.txt","r",stdin)

const int md = 1e8;
bool found[111][111][2];//0 == pehota 1 == horse
int dp[111][111][2];
int k1,k2;

int go(int n1, int n2, bool is_horse){
    if (n1==0 && n2==0)
        return 1;
    if (found[n1][n2][is_horse])
        return dp[n1][n2][is_horse];
    found[n1][n2][is_horse] = 1;

    int res=0;
    if (is_horse)
        for (int i=1;i<=min(n2,k2);i++)
            res = (res+go(n1,n2-i,0))%md;
    else
        for (int i=1;i<=min(n1,k1);i++)
            res = (res+go(n1-i,n2,1))%md;

    dp[n1][n2][is_horse]=res;
    return res;
}

int main(){
    int n1,n2;
    cin >> n1 >> n2 >> k1 >> k2;

    memset(found,sizeof(found),0);
    int ans = (go(n1,n2,0)+go(n1,n2,1))%md;

    cout << ans;
    return 0;
}