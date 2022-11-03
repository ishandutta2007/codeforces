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
    string s,ans;
    cin >> s;
    for (int i=0;i<s.length();i++)
        if (s[i]=='W' && i+1<s.length() && s[i+1]=='U' &&
                      i+2<s.length() && s[i+2]=='B')
                      {
                                    ans += "   ";
                                    i += 2;
                      }
        else
            ans += s[i];
    int y = 0,e = ans.length()-1;
    while (y<ans.length() && ans[y]==' ')y++;
    while (e>=0 && ans[e]==' ')e--;
    for (int i=y;i<=e;i++)
        cout << ans[i];
    return 0;
}

//**************************************