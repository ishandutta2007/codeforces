
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long
const int MOD = 2e9 + 7;
const int N = 3e5;
using namespace std;
vector<ll>sqr;
map<string,vector<string>> tk;
bitset<100> u;
int axis[102];
int ind(char c)
{
    return c - 'a';
}
const int maxn = 26;
int ok = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < u.size(); i++) u[i] = 1;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        string s;
        cin >> s;
        int sum = 0;
        if(c == '?')
        {
             if(ok) res++;
             u[ind(s[0])] = false;
        }
        if (c == '!')
        {
            if (ok) res++;
            bitset<100> used;
            for (int j = 0; j < s.size(); j++) used[ind(s[j])] = 1;
            for (int j = 0; j < maxn; j++) if(!used[j]) u[j] = used[j];
            
        }
        //--------------------
        if (c == '.')
        {
            for (int j = 0; j < s.size(); j++) u[ind(s[j])] = 0;
        }
        //----------------------
        for (int j = 0; j < maxn; j++) if(u[j]) sum++;
        if(sum == 1) ok = sum;
        //cout << ok << "\n;
        if(i == n - 1)
        {
            res--;
            res = max(0 , res);
        }
        //cout << sum << "\n;
    }
    cout << res << "\n";
    return 0;
}