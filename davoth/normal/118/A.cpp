#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<97){
            s[i]+=32;
        }
    }
    int s1=s.size();
    int cnt=0;
    for(int i=0;i<s1;i++){
        if(s[i-cnt]=='i'||s[i-cnt]=='a'||s[i-cnt]=='o'||s[i-cnt]=='u'||s[i-cnt]=='y'||s[i-cnt]=='e'){
            s.erase(s.begin()+i-cnt);
            cnt++;
        }
    }
    s1=s.size();
    cnt=0;
    for(int i=0;i<s1;i++){
        s.insert(s.begin()+i+cnt,'.');
        cnt++;
    }
    cout<<s;
    return 0;
}