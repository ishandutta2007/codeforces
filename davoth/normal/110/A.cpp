#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='4'||s[i]=='7'){
            cnt++;
        }
    }
    string ss=to_string(cnt);
    for(int i=0;i<ss.size();i++){
        if(ss[i]!='7'&&ss[i]!='4'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}