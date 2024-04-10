#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n,c=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        c-=temp;
        cin>>temp;
        c+=temp;
        if(c>b) b=c;
    }
    cout<<b;
    return 0;
}