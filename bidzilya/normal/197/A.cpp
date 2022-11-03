#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

int main()
{
    int a,b,r;
    cin >> a >> b >> r;
    if (2*r>min(a,b))
       cout << "Second" << endl;
    else    
            cout << "First" << endl;
    return 0;
}