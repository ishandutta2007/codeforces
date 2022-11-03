#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for (int i=1;i<4;i++){
        int a,b;
        cin >> a >> b;
        if (t==a)
            t = b;
        else
        if (t==b)
            t = a;
    }
    cout << t;
    return 0;
}