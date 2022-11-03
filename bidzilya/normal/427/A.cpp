#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;
  
typedef long long ll;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
        
    int n;
    int ans = 0;
    
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == -1) {
            if (c > 0) {
                --c;
            } else {
                ++ans;
            }
        } else {
            c += x;
        }
    }
    
    cout << ans << endl;
    

    return 0;
}