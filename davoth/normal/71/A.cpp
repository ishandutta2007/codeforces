#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        a.push_back(temp);
        if(a[i].size()>10){
            a[i]=a[i][0]+to_string(a[i].size()-2)+a[i][a[i].size()-1];
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}