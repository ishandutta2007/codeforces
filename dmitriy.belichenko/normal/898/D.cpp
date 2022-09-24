
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
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0, j = k - 1; j < n; j++)
    {
        if(a[j] - a[i] < m)
        {
            cnt++;
            a[j] = -1;
            if(i == j) i++;
        }
        else
        {
            i++;
            while(a[i] == -1) i++;
        }
    }
    cout << cnt << "\n";
}