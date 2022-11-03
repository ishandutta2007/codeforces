#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

double dp[201][201][402];
int p[202],a[202];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,l,k;
    scanf("%d%d%d",&n,&l,&k);
    for(int i=0;i<n;++i)
        scanf("%d",&p[i]);
    for(int j=0;j<n;++j)
        scanf("%d",&a[j]);
    dp[0][0][k+200]=1;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            for(int t=-200;t<=200;++t) {
                if (dp[i][j][t+200]>1e-100) {
                    if (a[i]==-1) {
                        dp[i+1][j+1][t+200-1]+=dp[i][j][t+200]*p[i]/100;
                        dp[i+1][j][t+200]+=dp[i][j][t+200]*(100-p[i])/100;
                    } else {
                        dp[i+1][j+1][min(400,t+200+a[i])]+=dp[i][j][t+200]*p[i]/100;
                        dp[i+1][j][t+200]+=dp[i][j][t+200]*(100-p[i])/100;
                    }
                }
            }
        }
    }
    double ans=0;
    for(int j=l;j<=n;++j)
        for(int t=0;t<=200;++t)
            ans+=dp[n][j][t+200];
    printf("%.7lf\n",ans);
    return 0;
}