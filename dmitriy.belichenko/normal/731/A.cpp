#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
#include<bitset>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#define fst first
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define sq(a) (long double)a * a
using namespace std;
typedef long long ll;
const int N = 200005;
int n , x, a[N], psum[N];
ll ans;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    char last = 'a';
    for(int i = 0; i < s.size(); i++)
    {
        ans += min(abs(s[i] - last ) ,26 - abs(s[i] - last ));
        last = s[i];
      //  cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}