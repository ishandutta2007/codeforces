#include <bits/stdc++.h>
using namespace std;
const int maxn  = 10000;
char s[maxn];
int main(){
    int n;
    cin>>n;
    cin>>s+1;
    int now = 1;
    int pos = 1;
    while (pos <= n){
        printf("%c",s[pos]);
        pos += now;
        now ++;
    }

    return 0;
}