#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int ss, ts;
    ss=(s[4]-'0')+(s[3]-'0')*10+(s[1]-'0')*60+(s[0]-'0')*600;
    ts=(t[4]-'0')+(t[3]-'0')*10+(t[1]-'0')*60+(t[0]-'0')*600;
    int d=ss-ts;
    if(d<0){
        d+=60*24;
    }
    int h=d/60;
    int m=d%60;
    cout << h/10 << h%10 << ':' << m/10 << m%10;
    return 0;
}