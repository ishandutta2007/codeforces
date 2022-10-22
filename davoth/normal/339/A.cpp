#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    string arr[(s.size()+1)/2];
    for(int i=0;i<s.size();i+=2){
        arr[i/2]=s[i];
    }
    sort(arr,arr+((s.size()+1)/2));
    for(int i=0;i<(s.size()+1)/2;i++){
        cout<<arr[i];
        if(i<((s.size()+1)/2-1)){
            cout<<'+';
        }
    }
    return 0;
}