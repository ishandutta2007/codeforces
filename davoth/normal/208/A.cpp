#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s.push_back(' ');
    s.push_back(' ');
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
            s.erase(s.begin()+i,s.begin()+i+3);
            s.insert(s.begin()+i, ' ');
        }
    }
    int i=0;
    while(i!=s.size()-1){
        if(s[i]==' '&&s[i+1]==' '){
            s.erase(s.begin()+i);
        }else i++;
    }
    if (s[0]==' '){
        s.erase(s.begin());
    }
    if (s[s.size()-1]==' '){
        s.erase(s.end()-1);
    }
    cout << s;
    return 0;
}