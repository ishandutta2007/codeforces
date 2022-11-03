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

int main()
{
    int sum = 0;
    int a,b,c;
    cin >> a >> b >> c;
    for (;a>1 && b>1 && c>1;a--,b--,c--)
        sum += (a+(b-1)+(c-1)+(a-1)+(b-1)+(c-2));
    if (a==1)
       sum += (b*c);
    else
    if (b==1)
       sum += (a*c);
    else
        sum += (a*b);
    cout << sum << endl;
 //   system("pause");
    return 0;
}