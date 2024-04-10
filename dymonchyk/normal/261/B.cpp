#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

double fact(double val,int n) {
    for(int i=1;i<=n;++i)
        val*=i;
    return val;
}

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,arr[55],p,s=0;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        s+=arr[i];
    }
    cin >> p;
    if (s<=p) {
        cout << n << endl;
        return 0;
    }
//  arr[n]=p+1; ++n;
    double ans=0;
    for(int k=0;k<n;++k) {
        double dp[55][55]={0};
        dp[0][0]=1;
        for(int t=0;t<n;++t) {
            if (t!=k)
                for(int i=n;i>=0;--i)
                    for(int j=0;j<=p;++j) {
                        if (dp[i][j]&&j+arr[t]<=p) {
                            dp[i+1][j+arr[t]]+=dp[i][j];
                        }
                    }
            for(int i=0;i<=n;++i)
                for(int j=0;j<=p;++j)
                    dp[i][j]/=t+1;
        }
//      cout << "www:" << k << endl;
        for(int i=0;i<n;++i) {
            for(int s=max(p-arr[k]+1,0);s<=p;++s) {
//              cout << dp[i][s] << endl;
//              cout << i << "  " << s << " " << i*fact(fact(dp[i][s],i),n-i-1) << endl;
                ans+=i*fact(fact(dp[i][s],i),n-i-1);
            }
        }
    }
    printf("%.6lf\n",ans);
//  for(int i=0;i<50;++i)
//      cout << i+1 << "    ";
    return 0;
}