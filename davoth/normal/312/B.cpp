#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double e=(a/b)/1.0,f=(c/d)/1.0;
    f*=(b-a)/b;
    double g=f+e,h=e/g;
    cout<<fixed<<setprecision(12)<<h;
    return 0;
}