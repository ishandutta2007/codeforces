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
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 10){
    cout << n+2 << endl;
    }
    else{
        cout << n-2 << endl;
    }
    return 0;
}