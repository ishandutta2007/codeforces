#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1100;
const int INF = 1000000000;

int x[110];
bool y[110];

int check(int a) {
    if (a == 0) return true;
    while (a > 0) {
       if (a % 10 == 0) return true;
       a /= 10;
    }
    return false;
}


int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[x[i]] = true;
    }
    
    vector<int> tt;
    if (y[100]) tt.push_back(100);
    if (y[0]) tt.push_back(0);
    
    bool flag = false;
    for (int i = 1; i < 10; ++i) {
       if (y[i]) {
           tt.push_back(i);
           flag = true;
           break;
       }
    }
    bool flag2 = false;
    for (int i = 10; i < 100; i += 10) {
       if (y[i]) {
           tt.push_back(i);
           flag2 = true;
           break;
       }
    }
    
    if (!flag && !flag2) {
		for (int i = 1; i < 100; ++i) {
		   if (y[i]) {
		       tt.push_back(i);
		       flag = true;
		       break;
		   }
		}
    }
    
    if (tt.size() == 0) {
        cout << 0 << endl;
    } else {
        cout << tt.size() << endl;
        cout << tt[0];
        for (int i = 1; i < tt.size(); ++i) cout << " " << tt[i];
        cout << endl;
    }

    return 0;
}