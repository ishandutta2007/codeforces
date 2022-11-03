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
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

int n,m,x,y;
int sm[1001];
int dp[1001][2];

int sum0(int l,int r){
    return (sm[r]-sm[l-1]);
}

int sum1(int l,int r){
    return ((r-l+1)*n-sm[r]+sm[l-1]);
}

int main(){
    cin >> n >> m >> x >> y;
    for (int i=0;i<=m;i++)sm[i]=0;
    for (int i=0;i<n;i++){       
        char c;
        for (int j=0;j<m;j++){
            cin >> c;
            if (c=='#')sm[j+1]++;
        }
    }
    for (int i=1;i<=m;i++)sm[i] += sm[i-1];
    dp[0][0]=dp[0][1]=0;
    for (int i=1;i<=m;i++){
        dp[i][0]=dp[i][1]=MAX_INT;
        for (int j=i-x+1;j>=max(1,i-y+1);j--){
            if (dp[j-1][0]!=MAX_INT)
               dp[i][1]=min(dp[i][1],dp[j-1][0]+sum0(j,i));
            if (dp[j-1][1]!=MAX_INT)
               dp[i][0]=min(dp[i][0],dp[j-1][1]+sum1(j,i));
        }
    }
    
    cout << min(dp[m][0],dp[m][1]) << endl;
 //   system("pause");
    return 0;
}