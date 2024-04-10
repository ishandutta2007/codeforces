#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int main(){
    int x;
    cin >> x;
    x++;
    while (1)
    {
        int e = x%10;
        int d = (x%100)/10;
        int s = (x%1000)/100;
        int f = x/1000;
        if (e!=d && e!=s && e!=f &&
            d!=s && d!=f &&
            s!=f)
            {
                cout << x << endl;
                break;
            }
        x++;
    }

    return 0;
}