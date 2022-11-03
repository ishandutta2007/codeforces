#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

bool Check(int h1, int a1, int d1, int h2, int a2, int d2)
{
    int delta1 = max(0, a1 - d2);
    int delta2 = max(0, a2 - d1);
    
    if (delta1 == 0) {
        return false;
    }
    
    if (delta2 == 0) {
        return true;
    }

    while (true) {
        h1 -= delta2;
        h2 -= delta1;
        
        if (h1 > 0 && h2 <= 0) {
            return true;
        }
        
        if (h1 <= 0) {
            return false;
        }
    }
}

int hpy, atky, defy;
int hpm, atkm, defm;
int h, a, d;
    
int Solve(int h1, int a1, int d1, int h2, int a2, int d2)
{
    int delta1 = max(0, a1 - d2);
    
    if (delta1 == 0) {
        return 1e9;
    }
    
    int delta2 = max(0, a2 - d1);
    
    if (delta2 == 0) {
        return 0;
    }
    
    int t = h2 / delta1;

    if (t * delta1 < h2) {
        ++t;
    }
    
    int cur = 1e9;
    for (int di = 0; di <= 300; ++di) {
        delta2 = max(0, a2 - d1 - di);
        
        if (delta2 == 0) {
            cur = min(cur, di * d);
        } else {
            if (h1 > delta2 * t) {
                cur = min(cur, di * d);
            } else {
                int hi = delta2 * t - h1 + 1;
                
                cur = min(cur, di * d + hi * h);
            }
        }
    }
    
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> hpy >> atky >> defy;
    cin >> hpm >> atkm >> defm;
    
    cin >> h >> a >> d;

    int ans = 1e9;
    
    for (int ai = 0; ai <= 300; ++ai) {
        ans = min(ans, a * ai + Solve(hpy, atky + ai, defy, hpm, atkm, defm));
    }

    cout << ans << endl;
    
    return 0;
}