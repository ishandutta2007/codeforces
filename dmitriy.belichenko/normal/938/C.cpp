#include <iostream>
#include <cstdio>
#include <utility>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <bitset>
#include <fstream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        bool flag = true;
        int mat = (ceil(sqrt(x))-1)*(ceil(sqrt(x))-1);
        int zero;
        int mat1;
        while (x >= mat/2) {
            if (flag) {
                mat = (sqrt(mat) + 1)*(sqrt(mat) + 1);
                if (x == 0) {
                    cout << "1 1" << '\n';
                    break;
                }
                zero = mat - x;
                mat1 = mat - 2*sqrt(mat) + 1;
                if (zero > 0 && (mat%zero == 0 || (mat1%zero == 0 && mat1 != zero)) && zero == round(sqrt(zero)) * round(sqrt(zero))) {
                    flag = false;
                    cout << sqrt(mat) << " ";
                    if (mat%zero == 0)
                        cout << sqrt(mat/zero) <<'\n';
                    else if (mat1%zero == 0)
                        cout << sqrt(floor(mat1/zero)) << '\n';
                    
                    break;
                }
                
            }
            
        }
        if(flag)
        for(int i = sqrt(x); i <= sqrt(x) + 10; i++) {
            for(int j = 2; j <= min(100 , i); j++) {
                if( i * i - (i / j) * (i / j) == x) {
                    cout << i << " " << j << "\n";
                    flag = 0;
                    break;
                }
            }
        }
        if (flag && x != mat && x!= 0) cout << -1 << '\n';
        flag = true;
        
    }
    
    
    return 0;
}