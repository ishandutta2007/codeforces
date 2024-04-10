#include <bits/stdc++.h>

using namespace std;

#define MAXN 300000

char str[5000000];
stack<char> St;
char Rev[500];

int main() {

    cin>>str;

    Rev['}'] = '{';
    Rev['>'] = '<';
    Rev[']'] = '[';
    Rev[')'] = '(';


    int sol = 0;

    for(int i=0; str[i]; i++) {
        if(strchr("([{<", str[i]))
            St.push(str[i]);
        else {
            if(St.empty()) {
                cout << "Impossible";
                return 0;
            } else {
                if(St.top() != Rev[str[i]])
                    sol += 1;
                St.pop();
            }
        }
    }

    if(!St.empty()) {
        cout << "Impossible";
        return 0;
    }

    cout << sol;


    return 0;
}