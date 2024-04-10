#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4

using namespace std;

    int x, y, x1, y1;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y >> x1 >> y1;
    if(x<=x1 && y<=y1){cout << "Polycarp"; return 0;}
    if(x>=x1 && y>=y1){cout << "Vasiliy"; return 0;}
    if(x>=x1 && y<=y1){
        if(y1-y < min(x, x-x1+y1-y)){cout << "Vasiliy"; return 0;}
        cout << "Polycarp";
        return 0;
    }
    if(x<=x1 && y>=y1){
        if(x1-x < min(y, y-y1+x1-x)){cout << "Vasiliy"; return 0;}
        cout << "Polycarp";
        return 0;
    }
}