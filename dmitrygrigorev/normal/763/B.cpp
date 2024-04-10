#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n, x1, ys, x2, y2;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
            cin >> x1 >> ys >> x2 >> y2;
        if (x1 % 2 == 0 && ys % 2 == 0){
            cout << 2 << endl;
        }
        else if (x1 % 2 == 0){
            cout << 1 << endl;
        }
        else if (ys % 2 == 0){
            cout << 3 << endl;
        }
        else{
            cout << 4 << endl;
        }
    }
    return 0;
}