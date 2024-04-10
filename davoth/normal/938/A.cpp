#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    string s;
    int l;
    cin>>l>>s;
    int a=1;
    while(a==1){
        a=0;
        for(int i=0;i<s.size()-1;i++){
            if((s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='e')&&(s[i+1]=='a'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u'||s[i+1]=='y'||s[i+1]=='e')){
                s.erase(s.begin()+i+1);
                a=1;
                continue;
            }
        }
    }
    cout<<s;
    return 0;
}