#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

char peek() {
    char p = s.top(); s.pop();
    char a = s.top();
    s.push(p);
    return a;
}

int main() {
    string k; cin >> k;
    for(char c:k) {
        s.push(c);
        while(s.size() > 1 && s.top() == peek()) {
            s.pop(); s.pop();
        }
    }
    if(s.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}