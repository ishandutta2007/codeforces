#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    cin>>s;
    int a=1;
    for(int i=1;i<s.size();i++){
        if(s[i]>96) a=0;
    }
    if(a){
        if(s[0]>96) s[0]-=32;
        else s[0]+=32;
        for(int i=1;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
    }
    cout<<s;
    return 0;
}