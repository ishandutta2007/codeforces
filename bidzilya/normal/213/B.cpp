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
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

int n;
int a[10];
ll c[222][222];
ll ans[10][101];

int main()
{
    for (int i=0;i<222;i++)
        c[i][0] = 1;
    for (int k=1;k<222;k++)
    {
        c[0][k] = 0;
        for (int i=1;i<222;i++)
            c[i][k]=(c[i-1][k]+c[i-1][k-1])%MD;
    }
    cin >> n;
    for (int i=0;i<10;i++) cin >> a[i];
    for (int i=0;i<10;i++)
        for (int j=0;j<=n;j++)
            ans[i][j] = 0;
    for (int i=a[9];i<=n;i++) ans[9][i] = 1;
    for (int cif=8;cif>=0;cif--)
        for (int i=0;i<=n;i++)
            for (int j=a[cif];j+i<=n;j++)
                if (i+j-(cif==0)>=0)
                   ans[cif][i+j] = (ans[cif][i+j]+ans[cif+1][i]*c[i+j-(cif==0)][j]%MD)%MD;                                    
    ll res = 0;
    for (int i=0;i<=n;i++)
        res = (res+ans[0][i])%MD;
    cout << res << endl;
    //system("pause");
    return 0;
}