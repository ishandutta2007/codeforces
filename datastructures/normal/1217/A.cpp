#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int sum=a+b+c;
        cout<<max(0,a+c-max(sum/2+1,a)+1)<<endl;
    }
    return 0;
}