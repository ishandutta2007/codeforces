#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ci,c=0;
    for(int i=1;;i++){
        c+=pow(2,i-1)*5;
        if(c>=n){
            ci=pow(2,i-1);
            break;
        }
    }
    c-=n;
    string a[]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout<<a[5-c/ci-1];
    return 0;
}