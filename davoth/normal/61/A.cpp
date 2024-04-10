#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin >> a >> b;
    string c=a;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) c[i]='1';
        else c[i]='0';
    }
    cout << c;
    return 0;
}