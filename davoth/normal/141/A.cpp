#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    s1=s1+s2;
    if(s1.size()!=s3.size()){
        cout << "NO";
        return 0;
    }
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s1.size(); j++){
            if(s1[i]==s3[j]){
                s1[i]=' ';
                s3[j]=' ';
                break;
            }
        }
    }
    s1=s1+s3;
    for (char i : s1) {
        if(i !=' '){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}