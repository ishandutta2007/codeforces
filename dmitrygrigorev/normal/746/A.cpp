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
    long long a, b, c;
    cin >> a >> b >> c;
    int counter = 0;
    int d = 1;
    while (true){
        if (d <= a & 2 * d <= b & 4*d <=c){
            counter += 7;
            d += 1;
        }
        else{
            break;
        }
    }
    cout << counter << endl;
    return 0;
    
}