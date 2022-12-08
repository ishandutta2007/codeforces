#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
char s[105];
bool able1[105], able2[105];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s+1);
        int n = strlen(s+1);

        bool able = 0;
        fill(able1, able1+102, 0);
        fill(able2, able2+102, 0);
        able1[0] = able2[n+1] = 1;
        int t1 = 0, t2 = n+1;
        for(int i=1; i<=n; i++){
            able1[i] = (able1[i-2] || able1[i-1]) && (s[i] == '0');
            if(able1[i]) t1 = i;
        }
        for(int i=n; i>=1; i--){
            able2[i] = (able2[i+2] || able2[i+1]) && (s[i] == '1');
            if(able2[i]) t2 = i;
        }
        printf("%s\n", t1+1 >= t2 ? "YES" : "NO");
    }
}