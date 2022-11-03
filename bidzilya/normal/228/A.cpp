#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int MAX_INT = 1e9;

int main(){
    int a[4];
    for (int i=0;i<4;i++)cin >> a[i];
    sort(a,a+4);
    int c =1;
    for (int i=1;i<4;i++)
        if (a[i]!=a[i-1])
           c++;
    cout << 4-c << endl;
//    system("pause");
    return 0;
}