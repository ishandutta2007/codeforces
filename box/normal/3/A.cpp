// luogu-judger-enable-o2
#include <iostream>
#include <algorithm>
using namespace std;

inline int abs(int x) {
    if(x >= 0) return x;
    else return -x;
}

int count(int left, int down) {
    int newleft = left, newdown = down, ans = 0;
    for(int i=0; i<max(0,min(left, down)); i++) { ans++; newleft--; newdown--; }
    for(int i=0; i<max(0,min(-left, down)); i++) { ans++; newleft++; newdown--; }
    for(int i=0; i<max(0,min(left, -down)); i++) { ans++; newleft--; newdown++; }
    for(int i=0; i<max(0,min(-left, -down)); i++) { ans++; newleft++; newdown++; }
    for(int i=0; i<max(0, newleft); i++) ans++;
    for(int i=0; i<max(0, -newleft); i++) ans++;
    for(int i=0; i<max(0, newdown); i++) ans++;
    for(int i=0; i<max(0, -newdown); i++) ans++;
    return ans;
}

int main() {
    char a; cin >> a;
    int row1 = a - 'a';
    int col1; cin >> col1;
    cin >> a;
    int row2 = a - 'a';
    int col2; cin >> col2;
    int left = row1-row2, down = col1-col2;
    cout << count(left, down) << endl;
    int newleft = left, newdown = down;
    for(int i=0; i<max(0,min(left, down)); i++) { cout << "LD" << endl; newleft--; newdown--; }
    for(int i=0; i<max(0,min(-left, down)); i++) { cout << "RD" << endl; newleft++; newdown--; }
    for(int i=0; i<max(0,min(left, -down)); i++) { cout << "LU" << endl; newleft--; newdown++; }
    for(int i=0; i<max(0,min(-left, -down)); i++) { cout << "RU" << endl; newleft++; newdown++; }
    for(int i=0; i<max(0, newleft); i++) cout << 'L' << endl;
    for(int i=0; i<max(0, -newleft); i++) cout << 'R' << endl;
    for(int i=0; i<max(0, newdown); i++) cout << 'D' << endl;
    for(int i=0; i<max(0, -newdown); i++) cout << 'U' << endl;
}