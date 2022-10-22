#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int abs(int a){
    if(a<0) a*=-1;
    return a;
}
int main(){
    int x,y;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp;
            cin>>temp;
            if(temp==1){
                x=i;
                y=j;
            }
        }
    }
    cout<<abs(2-x)+abs(2-y);
    return 0;
}