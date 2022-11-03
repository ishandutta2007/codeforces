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
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

int n;
vector< vector<int> > web;

int main()
{
    cin >> n;
    web.resize(n);
    for (int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        web[i].resize(k);
        for (int j=0;j<k;j++)
            cin >> web[i][j];
    }
    for (int i=0;i<n;i++)
        sort(web[i].begin(), web[i].end());
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        int l,r;
        l = ((i==0)?n-1:i-1);
        r = ((i==n-1)?0:i+1);
        int il=0;
        while (il<=web[l].size() && web[l][il]<web[i][0])il++;
        int ir=0;
        while (ir<=web[r].size() && web[r][ir]<web[i][0])ir++;
        for (int is=0;is<web[i].size()-1;is++)
        {
            int sl = 0;
            int sr = 0;
            while (il<web[l].size() && web[l][il]<web[i][is+1]){sl++;il++;}
            while (ir<web[r].size() && web[r][ir]<web[i][is+1]){sr++;ir++;}
            ans += (sl!=sr);
        }
    }    
    cout << ans << endl;
 //   system("pause");
    return 0;
}