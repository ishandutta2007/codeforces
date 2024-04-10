#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    if (n ==1){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    cout << 2 << endl;
    for (int i=2;i<=n + 1;i++){
        bool prime = true;
        for (int j=2;j*j<=i;j++){
            if (i % j == 0){
                prime = false;
            }
        }
        if (prime){
            cout << 1 << " ";
        }
        else cout << 2 << " ";
    }
    return 0;
}