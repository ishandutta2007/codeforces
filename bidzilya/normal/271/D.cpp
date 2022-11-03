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

string s;
set<ll> t;
int k;
int m[26];

int main(){
    cin >> s;
    for (int i=0; i<26; i++)
    {
        char tmp;
        cin >> tmp;
        m[i] = tmp - '0';
        m[i] = (m[i]+1)%2;
    }
    cin >> k;

    int ans = 0;
    for (int i=0; i<s.length(); i++)
    {
        int j = i;
        int sum = 0;
        ll h = 0;
        while (j < s.length())
        {
            sum += m[s[j]-'a'];
            h = h*29 + (s[j]-'a'+1);
            j++;
            if (sum > k)
                break;
            else
            if (t.find(h) == t.end())
            {
                t.insert(h);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}