/**********
*         *
*  HELLO  *
*         *
**********/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

int n, t, k, d;

int main()
{
    cin >> n >> t >> k >> d;
    int t1 = ((n + k - 1) / k)*t;
    if ((d + t) < t1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}