#include <bits/stdc++.h>

using namespace std;

bool contains(string &word, char a, char b) {
    for(int i=0; i<word.length(); i++)
        if(word[i] != a && word[i] != b)
            return false;
    return true;
}

int n;
string Word[5000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>Word[i];
    }

    int best = 0;

    for(char c='a'; c<='z'; c++)
    for(char d='a'; d<='z'; d++) {
        int total = 0;
        for(int i=1; i<=n; i++)
            total += contains(Word[i], c, d) * Word[i].length();
        best = max(best, total);
    }
    cout<<best;

    return 0;
}