#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int m(vector<int> a){
    int r=a[0],ci=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>r){
            r=a[i];
            ci=i;
        }
    }
    return ci;
}
int j(vector<int> a){
    int r=0;
    for(int i=0;i<a.size();i++){
        r+=a[i];
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    while(j(a)>=j(b)){
        b.push_back(a[m(a)]);
        a.erase(a.begin()+m(a));
    }
    cout<<b.size();
    return 0;
}