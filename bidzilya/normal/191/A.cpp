#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <cstdio>
using namespace std;

typedef long long lli;
typedef pair<lli,lli> pii;

int d[26][26];
int n;

int main()
{
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            d[i][j]=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int l = s.length();
        int cs = (int)s[0]-int('a');
        int cf = (int)s[l-1]-int('a');
        for (int j=0;j<26;j++)
            if (d[j][cs]!=0)
               d[j][cf] = max(d[j][cf],d[j][cs]+l);
        d[cs][cf] = max(d[cs][cf],l);
    }
    int ans = 0;
    for (int i=0;i<26;i++)
        ans = max(ans,d[i][i]);
    cout << ans;
    return 0;
}