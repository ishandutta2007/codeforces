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
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

int n;
string s1,s2;
ll a[26][222222];
ll s[26][222222];

int main()
{
    cin >> n;
    ll all = 0;
    for (ll cnt=n;cnt>0;cnt--)
        all += cnt*cnt;
    cin >> s1;
    cin >> s2;
    for (int c=0;c<26;c++)
    {
        a[c][0] = 0;
        s[c][0] = 0;
    }
    a[s2[0]-'A'][0]++;
    for (int i=1;i<n;i++)
    {
        for (int c=0;c<26;c++)
        {
            a[c][i] = a[c][i-1];
            s[c][i] = s[c][i-1];
        }
        a[s2[i]-'A'][i]++;
        s[s2[i]-'A'][i]+=i;
    }
    double num = 0.0;
    for (ll i=0;i<n;i++)
    {
        int c = s1[i]-'A';
        num = num + (a[c][i]+s[c][i])*(n-i)*1.0/all;
        num = num + (n*(a[c][n-1]-a[c][i])-(s[c][n-1]-s[c][i]))*(1+i)*1.0/all;
    }
    cout << setprecision(15) << num << endl;
    //system("pause");
    return 0;
}