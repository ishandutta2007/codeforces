#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='a') cnt++;
    }
    if(cnt*2>=s.size()){
        for(int i=0; i<s.size(); i++){
            if(s[i]<'a') s[i]=s[i]-'A'+'a';
        }
    }else{
        for(int i=0; i<s.size(); i++){
            if(s[i]>'Z') s[i]=s[i]+'A'-'a';
        }
    }
    cout << s;
    return 0;
}