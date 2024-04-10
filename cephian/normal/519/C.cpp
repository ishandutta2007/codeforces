#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int lanterns[1000];

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int teams = 0;
    while(true) {
        if(n > m) {
            if(n < 2 || m < 1)
                break;
            n-=2;
            m-=1;
        }
        else {
            if(n < 1 || m < 2)
                break;
            m-=2;
            n-=1;
        }
        ++teams;
    }
    cout << teams << "\n";
    
    return 0;
}