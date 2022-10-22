#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    int l1[n],l2[n];
    for(int i=0;i<n;i++){
        cin>>l1[i];
    }
    for(int i=0;i<n;i++){
        l2[l1[i]-1]=i+1;
    }
    for(int i=0;i<n;i++){
        cout<<l2[i]<<' ';
    }
    return 0;
}