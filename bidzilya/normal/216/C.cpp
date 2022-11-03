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

int n,m,k;

int main()
{
    cin >> n >> m >> k;
    if (k==1)
    {
             vector<int> ans;
             ans.push_back(1);
             for (int p=n;p<=(n+m);p+=(n-1))
                 ans.push_back(p);
             cout << ans.size() << endl;
             for (int i=0;i<ans.size();i++)
                 cout << ans[i] << " ";
             cout << endl;
             //system("pause");
             return 0;
    }
    if (n==m)  
       cout << (2*k+1)<< endl;
    else
        cout << (2*k) << endl;
    for (int i=0;i<k;i++)cout <<1 << " ";
    cout << n << " ";
    for (int i=0;i<k-1;i++)cout << (n+1) << " ";
    if (n==m)
       cout << (n+2);
    cout << endl;
    //system("pause");
    return 0;
}