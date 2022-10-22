#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int a[13]={0},b[4]={0};
int main() {
    string s,c[5];
    cin >> s >> c[0] >> c[1] >> c[2] >> c[3] >> c[4];
    if(s[0]=='T') a[8]=1;
    else if(s[0]=='J') a[9]=1;
    else if(s[0]=='Q') a[10]=1;
    else if(s[0]=='K') a[11]=1;
    else if(s[0]=='A') a[12]=1;
    else a[s[0]-'2']=1;
    if(s[1]=='D') b[0]=1;
    else if(s[1]=='C') b[1]=1;
    else if(s[1]=='S') b[2]=1;
    else if(s[1]=='H') b[3]=1;
    for(int i=0; i<5; i++){
        if(c[i][1]=='H' && b[3]){
            cout << "YES";
            return 0;
        }
        else if(c[i][1]=='D' && b[0]){
            cout << "YES";
            return 0;
        }
        else if(c[i][1]=='C' && b[1]){
            cout << "YES";
            return 0;
        }
        else if(c[i][1]=='S' && b[2]){
            cout << "YES";
            return 0;
        }
        else if(c[i][0]=='T' && a[8]){
            cout << "YES";
            return 0;
        }
        else if(c[i][0]=='J' && a[9]){
            cout << "YES";
            return 0;
        }
        else if(c[i][0]=='Q' && a[10]){
            cout << "YES";
            return 0;
        }
        else if(c[i][0]=='K' && a[11]){
            cout << "YES";
            return 0;
        }
        else if(c[i][0]=='A' && a[12]){
            cout << "YES";
            return 0;
        }
        else if(a[c[i][0]-'2']){
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
    return 0;
}