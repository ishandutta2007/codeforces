#include <iostream>
using namespace std;
int main(){
    int a[6];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
    int s=a[0]+a[1]+a[2];
    s=s*s;
    int d=a[0]*a[0]+a[2]*a[2]+a[4]*a[4];
    cout<<s-d;
    return 0;
}