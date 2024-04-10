#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
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
const int MAX_VALUE = (int)1e9;

//**************************************

int main()
{
    int n;
    cin >> n;
    ll p[50];
    for (int i=0;i<n;i++) cin >> p[i];
    ll s[5];
    for (int i=0;i<5;i++) cin >> s[i];
    ll ans[5];
    for (int i=0;i<5;i++) ans[i] = 0;
    ll sum = 0;
    for (int i=0;i<n;i++)
    {
        sum += p[i];
        for (int j=4;j>=0;j--)
            if (sum>=s[j])
            {
                          ans[j] += sum/s[j];
                          sum %= s[j];
            }
    }
    for (int i=0;i<5;i++)
        cout << ans[i] << " ";
    cout << endl;
    cout << sum;
    return 0;
}

//**************************************