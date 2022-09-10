#include<bits/stdc++.h>
using namespace std;
void Mike() {
    puts("Mike");
}
void Ann() {
    puts("Ann");
}
int dp[128];
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        bool win = 0;
        for(int j = 'a' ; j < s[i]; j++) {
            if(dp[j]) {
                win = 1;
                break;
            }
        }
        if(win) Ann();
        else {
            Mike();
            dp[s[i]] = 1;
        }
    }
    return 0;
}