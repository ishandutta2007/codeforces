#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp[3];
        cin>>temp[0]>>temp[1]>>temp[2];
        if(temp[0]+temp[1]+temp[2]>1) cnt++;
    }
    cout<<cnt;
    return 0;
}