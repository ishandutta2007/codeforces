#include <bits/stdc++.h>

using namespace std;

bool Good[5000000];
int Use[5000000];
char str[5000000];
int p, q;

void Output(int n) {
    if(n == 0) return;

    char aux = str[n+1];
    str[n+1] = 0;

    if(Use[n] == p) {
        Output(n - p);
        cout << str + n - p + 1 << '\n';

    } else {
        Output(n - q);
        cout << str + n - q + 1 << '\n';
    }

    str[n+1] = aux;
}

int main() {

    int n;
    cin>>n>>p>>q;
    Good[0] = 1;
    for(int i=1; i<=n; i++) {
        if(i>=p && Good[i-p]) {
            Good[i] = 1;
            Use[i] = p;
        }
        if(i>=q && Good[i-q]) {
            Good[i] = 1;
            Use[i] = q;
        }
    }

    cin>>str + 1;

    if(!Good[n]) {
        cout << "-1";
    } else {
        int cnt = 0;
        for(int i = n; i; i -= Use[i])
            cnt ++;
        cout << cnt << '\n';
        Output(n);
    }

    return 0;
}