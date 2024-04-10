#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 1e5;
bool used[N][10];
set<string> ans;
string s;
void dfs(int u , int c)
{
    if(used[u][c]) return;
    if(u - c < 5) return;
    used[u][c] = 1;
    pair<string, string> a;
    a.fst = s.substr(u - c , c);
    a.snd = s.substr(u - 2 * c , c);
  //  cout << a.fst << " " << a.snd << "\n";
    ans.insert(a.first);
    if(a.fst != a.snd)
    {
         if(u - c >= 5)
            dfs(u - c , c);
    }
    if(u - c >= 5) dfs(u - c , 5 - c);

    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    dfs(s.size(), 3);
    dfs(s.size(), 5 - 3);
    cout << ans.size() << "\n";
    for(auto i : ans)
    {
        cout << i << "\n";
    }
    return 0;
}