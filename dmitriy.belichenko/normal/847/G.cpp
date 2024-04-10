
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
typedef long long ll;
using namespace std;

int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = -1;
    for(int j = 0; j < 7; j++)
    {
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i][j] == '1') mx++;
        }
        ans = max(mx , ans);
    }
    cout << ans << "\n";
}