#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> xval, yval;

int main() {
    cin >> n;
    if (n >= 2) {
        int x, y;
        cin >> x >> y;
        xval.push_back(x);     
        yval.push_back(y);  
        for (int i = 1; i < n; ++i) {
            cin >> x >> y;
            if(find(xval.begin(), xval.end(), x) == xval.end()) {
                xval.push_back(x);
            } 
            if(find(yval.begin(), yval.end(), y) == yval.end()) {
                yval.push_back(y);
            } 
        }
        
        if (xval.size() == 2 && yval.size() == 2) {
            int ans = (xval[1]-xval[0])*(yval[1]-yval[0]);
            
            if (ans < 0) {
                ans = abs(ans);
            }
            
            cout << ans;
        } else {
            cout << -1;
        }
    } else {
        cout << -1;
    }
}