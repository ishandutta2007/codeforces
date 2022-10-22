#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int a=n-(1+w)*w/2*k;
    if(a<0){
        cout<<a*-1;
    }else{
        cout<<0;
    }
    return 0;
}