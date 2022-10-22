#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    int m=-1;
    for(int i=0; i<n; i++){
        if(s[i][0]=='O' && s[i][1] == 'O'){
            s[i][0]='+';
            s[i][1]='+';
            break;
        }else if(s[i][3]=='O' && s[i][4] == 'O'){
            s[i][3]='+';
            s[i][4]='+';
            break;
        }
        m=i;
    }
    if(m==n-1) cout << "NO";
    else{
        cout << "YES\n";
        for(int i=0; i<n; i++){
            cout << s[i] << '\n';
        }
    }
    return 0;
}