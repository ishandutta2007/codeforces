#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i , n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int N = 1e5 + 100;
ll INF = 1LL << 62;
const int MOD = 1e9 + 7;
vector<int>g[N];
vector<int> ans;
bool used[N];
int mx = -1;
int color[N];
int p[N];
int st = -1, send;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  freopen("input.txt" , "r" , stdin);
  //  freopen("output.txt" , "w" , stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i - 1] == 'S' && s[i] == 'F') cnt++;
        if(s[i - 1] == 'F' && s[i] == 'S') cnt--;
    }
   // cout << cnt << "\n";
    if(cnt > 0) cout << "YES";
    else cout << "NO";
    cout << "\n";
    return 0;
}