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
int n, m, k;
int main(){
    cin >> n >> m >> k;
    k -= 1;
    int ryad = k / (2 * m) + 1;
    int parta = (k - 2 * m * (ryad - 1)) / 2 + 1;
    if (k % 2 == 0){
        cout << ryad << " " << parta << " L";
        return 0;
    }
    cout << ryad << " " << parta << " R";
    return 0;
    
}