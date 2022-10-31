#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
char s[maxn];
int main(){
    int n,k;
    cin>>n>>k;
    int d = n-k;
    d >>= 1;
    for (int i=0;i<d;i++){
        s[i] = '0';
    }
    s[d++] = '1';
    int idx = 0;
    for (int i=0;i<n;i++){
        printf("%c",s[idx++]);
        if (idx == d)idx = 0;
    }
    puts("");
    return 0;
}