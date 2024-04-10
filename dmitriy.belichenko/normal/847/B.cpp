
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
    int n , last = 0;
    cin >> n;
    vector<int> a;
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        int u , x;
        cin >> u;
        x = -u;
        if( upper_bound(a.begin(), a.end(), x) == a.end() )
        {
            ans.pb({x});
            a.pb(x);
        }
        else
        {
            int p =  upper_bound(a.begin(), a.end(), x)- a.begin();
            ans[p].pb(x);
            a[p] = x;
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << -ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

}