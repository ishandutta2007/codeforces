#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <cstdio>
using namespace std;

typedef long long lli;

int main()
{
    int n,l,k;
    cin >> n >> l >> k;
    double d[2][222][222];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            d[0][i][j]=0;
    if (k>n)
       d[0][0][n]=1;
    else
        d[0][0][k]=1;
    double p[200];
    for (int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        p[i] = a/100.0;
    }
    int pp=0;
    for (int ii=0;ii<n;ii++)
    {
        int a;
        cin >> a;
        a++;
        
        int nx=(pp+1)%2;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)           
                d[nx][i][j]=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
            {
                //win
                if (i<n)
                        if (j+a>n)
                           d[nx][i+1][n] += p[ii]*d[pp][i][j];
                        else
                            d[nx][i+1][a+j] += p[ii]*d[pp][i][j];
                //lose
                d[nx][i][j] += (1-p[ii])*d[pp][i][j];
            }
        pp = nx;
    }
    double ans = 0.0;
    for (int i=l;i<=n;i++)
        for (int j=i;j<=n;j++)
            ans += d[pp][i][j];
    cout << setprecision(10) << ans;
    return 0;
}