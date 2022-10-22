#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;


int main() {
    int n;
    int x[4][4];
    cin >> n;
    for (int i = 0; i < 4; ++i) 
     for (int j = 0; j < 4; ++j) cin >> x[i][j];
    
    for (int i = 0; i < 4; ++i) {
        if (x[i][0] + x[i][2] <= n) { 
            cout << i+1 << " " << x[i][0] << " " <<  n-x[i][0] << endl; 
            return 0;
        }
        if (x[i][0] + x[i][3] <= n){ 
            cout << i+1 << " " << x[i][0] << " " <<  n-x[i][0] << endl; 
            return 0;
        }
        if (x[i][1] + x[i][2] <= n){ 
            cout << i+1 << " " << x[i][1] << " " <<  n-x[i][1] << endl; 
            return 0;
        }
        if (x[i][1] + x[i][3] <= n) { 
            cout << i+1 << " " << x[i][1] << " " <<  n-x[i][1] << endl; 
            return 0;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}