#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld a, b, c;
ld delta;

int main() {
    cin>>a>>b>>c;
    delta = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0) {
        cout<<"-1\n";
        return 0;
    }
    if (a == 0) {
        if (b == 0) {
            cout<<"0\n";
            return 0;
        }
        ld x = - c / b;
        cout<<"1\n";
        cout<<fixed<<setprecision(100)<<x<<"\n";
        return 0;
    }
    if (delta < 0) {
        cout<<"0\n";
        return 0;
    }
    if (delta == 0) {
        ld x = - b / (2 * a);
        cout<<"1\n";
        cout<<fixed<<setprecision(100)<<x<<"\n";
        return 0;
    }
    ld x = ( - b + sqrt(delta) ) / (2 * a);
    ld y = ( - b - sqrt(delta) ) / (2 * a);
    if (x > y) {
        swap(x, y);
    }
    cout<<"2\n";
    cout<<fixed<<setprecision(100)<<x<<"\n";
    cout<<fixed<<setprecision(100)<<y<<"\n";
    return 0;
}
/**

bx + c = 0
x = -c / b;

**/