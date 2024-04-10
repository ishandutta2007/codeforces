#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a['z'-'a'+1]={0};
    for(int i=0; i<n; i++){
        if(s[i]<'a') s[i]+='a'-'A';
        a[s[i]-'a']=1;
    }
    for(int i=0; i<'z'-'a'+1; i++){
        if(a[i]!=1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}