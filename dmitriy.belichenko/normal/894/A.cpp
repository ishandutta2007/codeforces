#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;
pair<int,int> a[22];
int b[22];
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'Q')
        {
            for(int j = i + 1; j < s.size(); j++)
            {
                if(s[j] == 'A')
                {
                    for(int k = j + 1; k < s.size(); k++)
                    {
                        if(s[k] == 'Q')
                            ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}