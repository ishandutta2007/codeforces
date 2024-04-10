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
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
const int MOD = 1e9 + 7;
const int N = 1e5;
using namespace std;
map<pair<int, int> , int> cnt;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        if(x > 0 ) cnt1++;
        else cnt2++;
    }
    if(cnt1 > 1 && cnt2 > 1)
    {
        cout << "No";
    }
    else
        cout << "Yes";
    
    
}