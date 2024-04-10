#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n,x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        if(temp[1]=='+') x++;
        else x--;
    }
    cout<<x;
    return 0;
}