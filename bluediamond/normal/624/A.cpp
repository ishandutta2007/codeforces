#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double d,l,v1,v2;
    cin>>d>>l>>v1>>v2;
    cout<<fixed<<setprecision(10)<<(l-d)/(v1+v2);
    return 0;
}