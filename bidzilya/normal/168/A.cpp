#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const double eps = 1e-5;

int main(){
    int n,x,t=0,y;
    cin >> n >> x >> y;
    while (1){
        double pp = 100.0*(x+t)/n;
        if (pp>=y)
            break;
        t++;
    }
    cout << t << endl;
    return 0;
}