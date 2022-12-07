#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

bool anyVisible = false;

bool isInside(float x, float y, float x3, float y3, float x4, float y4) {
    if( (x<x3 || x>x4) || (y<y3 || y>y4)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    if(x3 > x4) swap(x3, x4);
    if(y3 > y4) swap(y3, y4);
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    if(x5 > x6) swap(x5, x6);
    if(y5 > y6) swap(y5, y6);
    // Check for every edge piece.
    // cout << isInside(1000000-0.5, 1000000, x3, y3, x4, y4) << endl;
    // cout << isInside(1000000-0.5, 1000000, x5, y5, x6, y6) << endl;
    for(float i=y1+0.5; i<y2; i+=0.5) {
        if((!isInside(x1,i,x3,y3,x4,y4))&&(!isInside(x1,i,x5,y5,x6,y6))) {
            cout << "YES";
            return 0;
        }
        if((!isInside(x2,i,x3,y3,x4,y4))&&(!isInside(x2,i,x5,y5,x6,y6))) {
            cout << "YES";
            return 0;
        }
    }
    for(float i=x1+0.5; i<x2; i+=0.5) {
        if((!isInside(i,y1,x3,y3,x4,y4))&&(!isInside(i,y1,x5,y5,x6,y6))) {
            cout << "YES";
            return 0;
        }
        if((!isInside(i,y2,x3,y3,x4,y4))&&(!isInside(i,y2,x5,y5,x6,y6))) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}