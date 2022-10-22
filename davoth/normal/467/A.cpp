#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        if(temp2-temp1>1) cnt++;
    }
    cout<<cnt;
    return 0;
}