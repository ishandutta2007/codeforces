#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    set<string>st;
    map<string,int> cnt;

    for(int i = 0; i < n; i++)
    {
     
        cin >> s[i];
        st.insert(s[i]);
        cnt[s[i]] = 0;
    }
      vector<string> ans;

    for(int i = n - 1; i >= 0; i--)
    {
        if(cnt[s[i]] == 0)
        {
          ans.pb(s[i]);
         cnt[s[i]] ++;
        }
    }
    for(int i = 0; i < st.size(); i++)
    {
        cout << ans[i] << endl;
    }
}