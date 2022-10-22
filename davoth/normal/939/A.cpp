#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<n;i++){
        if(a[a[a[i]-1]-1]==(i+1)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}