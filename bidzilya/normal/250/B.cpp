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

void Obr(const string& s, int l, const int r)
{
    while (l<=r)
    {
        int u = l;
        while (u<=r && s[u]!=':')u++;
        int cnt = 4-(u-l);
        for (int i=0;i<cnt;i++)
            cout << 0;
        for (int i=l;i<u;i++)
            cout << s[i];
        if (u < r)
            cout << ":";
        l = u+1;
    }

}

int main(){
    int n;
    string s;
    cin >> n;
    for (;n>0;n--)
    {
        cin >> s;
        bool cm = false;
        for (int i=0;i<s.length()-1;i++)
            if (s[i]==':' && s[i+1]==':')
            {
                int cntl = 0, cntr = 0;
                for (int j=0;j<i;j++)
                    if (s[j] == ':')
                        cntl++;
                for (int j=i+2;j<s.length();j++)
                    if (s[j] == ':')
                        cntr++;
                int cnt = 8;
                if (i != 0)
                    cnt -= (cntl+1);
                if ((i+1) != s.length()-1)
                    cnt -= (cntr+1);
                Obr(s, 0, i-1);
                if (i !=0)
                    cout << ":";
                for (int j=0;j<cnt-1;j++)
                    cout << "0000:";
                cout << "0000";
                if ((i+1) != s.length()-1)
                    cout << ":";
                Obr(s, i+2, s.length()-1);
                cm = true;
            }
            if (!cm)
                Obr(s, 0, s.length()-1);
            cout << endl;
    }

    return 0;
}