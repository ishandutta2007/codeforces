
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
int axis[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i * i <= 2e9; i++)
    {
        sqr.pb(i * i);
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> del(n);
    vector<int> add(n);
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int sq = lower_bound(sqr.begin(), sqr.end(),  a[i]) - sqr.begin();
        del[i] = abs(a[i] - sqr[sq]);
       //cout << a[i] << " " << sq << "\n";
        if(sq != 0)
        {
            sq--;
            del[i] = min(del[i] ,(int)abs(a[i] -  sqr[sq]));
        }
        if(del[i] == 0)
        {
            cnt++;
            add[i] = 1;
            if(a[i] == 0) add[i]++;
        }
    }
    sort(del.begin(), del.end());
  //  for(int i = 0; i < n; i++) cout <<  del[i] << " ";
  //  cout << "\n";
    sort(add.begin(), add.end());
    if(cnt < n / 2)
    {
        for(int i = 0; i < n && cnt < n / 2; i++)
        {
            if(del[i] != 0)
            {
                cnt++;
                ans += del[i];
            }
        }
    }
    else
    {
        for(int i = 0; i < n && cnt > n / 2; i++)
        {
            if(add[i] != 0)
            {
                cnt--;
                ans += add[i];
            }
        }

    }
    cout <<  ans  << "\n";
}