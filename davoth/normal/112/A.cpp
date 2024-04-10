#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        if(s1[i]<97){
            s1[i]+=32;
        }
        if(s2[i]<97){
            s2[i]+=32;
        }
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]>s2[i]){
            cout<<1;
            return 0;
        }else if (s1[i]<s2[i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}