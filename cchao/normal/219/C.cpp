#include <cstdio>
#include <iostream>
using namespace std;
int n, k;
char s[500010], sa[500010]={0}, sb[500010]={0};
int main(){
    scanf("%d%d%s", &n, &k, s);
    if(k==2){
        int a = 0, b = 0, c = 'A';
        for(int i = 0; i < n; ++i){
            sa[i] = c;
            if(s[i] != c) ++a;
            c = c=='A' ? 'B' : 'A';
        }
        c = 'B';
        for(int i = 0; i < n; ++i){
            sb[i] = c;
            if(s[i] != c) ++b;
            c = c=='A' ? 'B' : 'A';
        }
        if(a<b) printf("%d\n%s\n", a, sa);
        else printf("%d\n%s\n", b, sb);
    }
    else{
        int ans = 0;
        for(int i = 0; i < n-1; ++i){
            if(s[i] == s[i+1]){
                ++ans;
                int c='A';
                while(c==s[i] || c==s[i+2]) ++c;
                s[i+1] = c;
            }
        }
        printf("%d\n%s\n", ans, s);
    }
    return 0;
}