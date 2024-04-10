//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
#define in cin
#define out cout
int a, b;
int workgcd(int A, int B)
{
    return B ? A / B + workgcd(B, A % B) : 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    in >> a >> b;
    out << workgcd(a, b) << endl;
    return 0;
}