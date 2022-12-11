#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265359

typedef long double ll;

int main(){
    ll x1, y1 ,r1;
    cin >> x1 >> y1 >> r1;
    ll x2, y2 ,r2;
    cin >> x2 >> y2 >> r2;
    
    ll d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    
    if(d + 0.0000001 > r1 + r2){ 
        cout << 0.00000000 << endl;
        return 0;
    }
    else if(d - 0.0000001 + r1 < r2){
         cout << setprecision(10) << fixed << r1*r1*PI << endl;
         return 0;
    }
    else if(d - 0.0000001 + r2 < r1){
         cout << setprecision(10) << fixed << r2*r2*PI << endl;
         return 0;
    }
    
    ll bet = acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
    ll alf = acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
    
    if(bet > PI/2){
        bet -= PI;
        ll ar = abs(r1*r1*alf) - abs(r1*r1*sin(2.0*alf)/2.0);
        ll are = abs(r2*r2*bet) - abs(r2*r2*sin(2.0*bet)/2.0);
        
        cout << setprecision(10) << fixed << r2*r2*PI - (are - ar) << endl;
        return 0;
    }
    if(alf > PI/2){
        alf -= PI;
        ll ar = abs(r1*r1*alf) - abs(r1*r1*sin(2.0*alf)/2.0);
        ll are = abs(r2*r2*bet) - abs(r2*r2*sin(2.0*bet)/2.0);
        
        cout << setprecision(10) << fixed << r1*r1*PI - (ar - are) << endl;
        return 0;
    }
    
    ll ar = abs(r1*r1*alf) - abs(r1*r1*sin(2.0*alf)/2.0);
    ll are = abs(r2*r2*bet) - abs(r2*r2*sin(2.0*bet)/2.0);
    
    cout << setprecision(10) << fixed << ar + are << endl;
}