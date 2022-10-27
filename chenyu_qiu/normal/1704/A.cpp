#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin >> t;
int i, j;
int n, m, g, h;
string s, l;
for(i=0; i<t; i++){
    cin >> n;
    cin >> m;
    cin >> s;
    cin >> l;
    if(m>n){
        cout << "NO" << "\n";
        continue;
    }
    g=0;
    for(j=1; j<m; j++){
        if(l[j]!=s[j+n-m]){
            cout << "NO" << "\n";
            g=1;
            break;
        }
    }
    h=0;
    if(g==0){
        if(l[0]==s[n-m]){
            cout << "YES" << "\n";
        }
        else{
            for(j=0; j<n-m; j++){
            if(s[j]!=s[j+1]){
                cout << "YES" << "\n";
                h=1;
                break;
                 }
            }
            if(h==0){
                cout << "NO" << "\n";
            }
 
        }
    }
}
}