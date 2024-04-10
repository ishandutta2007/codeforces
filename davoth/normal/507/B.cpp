#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    double r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    double a=sqrt(pow(x1-x,2)+pow(y1-y,2));
    cout<<ceil(a/2/r);
    return 0;
}