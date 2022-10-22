#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[s2.size()-1-i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}