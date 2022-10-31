#include <bits/stdc++.h>
using namespace std;
set<char> used1,used2;
string temp;
int main(){
    cin>>temp;
    string t;
    for (int i=0;i<5;i++){
        cin>>t;
        used1.insert(t[0]);
        used2.insert(t[1]);
    }
    if (used1.count(temp[0]) || used2.count(temp[1])){
        puts("YES");
    }else{
        puts("NO");
    }

    return 0;
}