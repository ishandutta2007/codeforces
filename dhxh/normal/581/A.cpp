#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int i, j;
    int a, b;
    
    cin >> a >> b;
    
    cout << min(a, b) << " " << (a + b - 2 * min(a, b)) / 2 << endl;
    
    return 0;
}