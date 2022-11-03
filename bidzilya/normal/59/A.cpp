#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string s;

int main(){
    cin >> s;
    int C=0,c=0;
    for (int i=0;i<s.length();i++){
        if (s[i]>='a' && s[i]<='z')
            c++;
        if (s[i]>='A' && s[i]<='Z')
            C++;
    }
    bool is_big = (C>c);
    for (int i=0;i<s.length();i++){
        if (is_big && s[i]>='a' && s[i]<='z')
            s[i]-=32;
        if (!is_big && s[i]>='A' && s[i]<='Z')
            s[i]+=32;
    }
    cout << s;
    return 0;
}