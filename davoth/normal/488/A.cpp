#include <bits/stdc++.h>
using namespace std;
int main() {
    int f,c=0;
    cin >> f;
    int a=f;
    while(true){
        a++;
        string s=to_string(a);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='8'){
                c=1;
                break;
            }
        }
        if(c) break;
    }
    cout <<  a-f;
    return 0;
}