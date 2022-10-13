#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;
typedef int var;

bool Sol[50000];

int main() {
    //freopen("debug.in", "r", stdin);
    //freopen("debug.out", "w", stdout);

    for(var i=0; i<=999; i+=8) {
        Sol[i] = 1;
    }

    string s;
    cin>>s;

    for(var i=0; i<s.size(); i++) {
        if(s[i] == '0' || s[i] == '8') {
            cout<<"YES\n"<<s[i];
            return 0;
        }
    }

    for(var i=0; i<s.size(); i++) {
        for(var j=i+1; j<s.size(); j++) {
            var n = 10*(s[i]-'0')+s[j]-'0';
            if(Sol[n]) {
                cout<<"YES\n"<<n;
                return 0;
            }
        }
    }

    for(var i=0; i<s.size(); i++) {
        for(var j=i+1; j<s.size(); j++) {
            for(var k=j+1; k<s.size(); k++) {
                var n = (((s[i] - '0')*10 + s[j] - '0')*10 + s[k]-'0');
                if(Sol[n]) {
                    cout<<"YES\n"<<n;
                    return 0;
                }
            }
        }
    }



    cout<<"NO\n";


    return 0;
}