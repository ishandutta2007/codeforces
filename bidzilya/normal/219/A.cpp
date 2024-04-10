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
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

int k;
string s;
int a[26];

int main()
{
    cin >> k;
    cin >> s;
    for (int i=0;i<26;i++)a[i] = 0;
    for (int i=0;i<s.length();i++)
        a[s[i]-'a']++;
    for (int i=0;i<26;i++)
        if (a[i]%k!=0)
        {
                      cout << -1 << endl;
                      return 0;
        }
    for (int i=0;i<k;i++)
        for (int j=0;j<26;j++)
            for (int c=0;c<a[j]/k;c++)
                cout << (char)('a'+j);
    cout << endl;
   // system("pause");
    return 0;
}