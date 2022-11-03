#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int sum=0,n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        int p;
        cin >> p;
        sum += p;
    }
    double res = 1.0*sum/n;
    cout << setprecision(10);
    cout << res;
    return 0;
}