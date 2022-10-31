#include <bits/stdc++.h>
using namespace std;
string s;
int last;
int main(){
    cin>>s;
    last=-1;
    for (int i=0;i<s.size();++i)
    if (s[i]!='a'){
        last=i;
        break;
    }
    if (last==-1) s[s.size()-1]='z';
    else{
        for (int i=last;i<s.size();++i){
            if (s[i]=='a') break;
            else s[i]=char(s[i]-1);
        }
    }
    cout<<s;
}