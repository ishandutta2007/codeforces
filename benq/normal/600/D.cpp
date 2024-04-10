#include<bits/stdc++.h>
using namespace std;

#define ld long double

int main() {
    ld P=3.1415926535897932384;
    ld x1,y1,r1,x2,y2,r2,a1,a2,num1,num2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ld  d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    cout << fixed << setprecision(10);
    if (d >= (r1+r2)) cout << 0;
    else if (r2>=d+r1) cout << P*r1*r1;
    else if (r1>=d+r2) cout << P*r2*r2;
    else {
        a1=2*acos((d*d+r1*r1-r2*r2)/(2*d*r1));
        a2=2*acos((d*d+r2*r2-r1*r1)/(2*d*r2));
        
        num1=(ld)a1/2*r1*r1-r1*r1*sin(a1)*0.5;
        num2=(ld)a2/2*r2*r2-r2*r2*sin(a2)*0.5;
        cout << (num1+num2);
    }
}