#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    double x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    double t=999999;
    for(int i=0;i<n;i++){
        double x1,y1,v;
        cin>>x1>>y1>>v;
        if(sqrt(pow(x1-x,2)+pow(y1-y,2))/v<t){
            t=sqrt(pow(x1-x,2)+pow(y1-y,2))/v;
        }
    }
    cout<<setprecision(7)<<fixed<<t;
    return 0;
}