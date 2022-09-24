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
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> cur = {1 , 2};
    for(int i= 1; i <= n; i++)
    {
        int x;
        cin >> x;
        set<int> now;
        now.insert(x);
        if(cur.count(x) == 1)
        {
            for(auto j : cur)
            {
                if(j != x)
                    now.insert(6 - j - x);
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
        cur = now;
        
    }
    cout << "YES" << "\n";
    
}