#include <bits/stdc++.h>
using namespace std;
string s;
int one,two;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='1'){
            ++one;
            two=0;
            if (one==7) {
                cout<<"YES";
                return 0;
            }
        } else {
            ++two;
            one=0;
            if (two==7){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}