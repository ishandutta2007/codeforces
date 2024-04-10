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

int main()
{
    int n;
    cin >> n;
    int a[111];
    for (int i=0;i<n;i++) cin >> a[i];
    int m;
    cin >> m;
    int b[111];
    for (int i=0;i<m;i++) cin >> b[i];
    int cnt = 0;
    int mx;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (b[j]%a[i]==0)
            {
                             int k = b[j]/a[i];
                             if (cnt==0 || k>mx)
                             {
                                        mx = k;
                                        cnt=1;
                                        }else
                             if (cnt!=0 && k==mx)
                                cnt++;
            }
    cout << cnt << endl;
    
    //system("pause");
    return 0;
}