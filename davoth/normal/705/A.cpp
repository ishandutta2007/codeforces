#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m=n;
    n--;
    string s="I hate ";
    while(n){
        if((m-n)%2==1) s+="that I love ";
        else s+="that I hate ";
        n--;
    }
    s+="it";
    cout << s;
    return 0;
}