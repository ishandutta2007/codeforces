#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

double Dy[2003][2003];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,t; double p;
    scanf("%d %lf %d",&n,&p,&t);

    int i,j;
    double ans=0.0;
    Dy[0][0] = 1;
    for(i=1; i<=t; i++){
        Dy[0][i] = Dy[0][i-1] * (1.0-p);
    }
    for(i=1; i<n; i++){
        for(j=1; j<=t; j++){
            Dy[i][j] = Dy[i][j-1] * (1.0-p) + Dy[i-1][j-1] * p;
        }
        ans += Dy[i][t] * i;
    }
    for(j=1; j<=t; j++){
            Dy[n][j] = Dy[n][j-1] + Dy[n-1][j-1] * p;
    }
    ans += Dy[i][t] * i;

    printf("%lf\n",ans);

    return 0;
}