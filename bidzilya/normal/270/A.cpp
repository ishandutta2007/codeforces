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
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        int sum = 180;
        bool found = false;
        for (int i=3; i<=1000; i++)
        {
            if (sum == a*i)
            {
                found = true;
                break;
            }
            sum += 180;
        }
        cout << (found?"YES":"NO") << endl;
    }

    return 0;
}