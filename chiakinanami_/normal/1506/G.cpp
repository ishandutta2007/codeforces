#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
char s[200005];
int DP[200005];
multiset<char> c;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s+1);
        n = strlen(s+1);

        fill(DP, DP+n+2, 0);
        for(int i=n; i>=0; i--){
            DP[i] = DP[i+1] | (1<<(s[i] - 'a'));
        }

        int pnt = 1;
        int all = DP[1];
        while(all){
            int loc = 0; char chr = ' ';
            for(int i=pnt; i<=n; i++){
                if(!((all >> (s[i] - 'a')) & 1)) continue;
                if((DP[i] & all) != all) break;
                if(chr < s[i]){
                    chr = s[i];
                    loc = i;
                }
            }
            printf("%c", chr);
            pnt = loc+1;
            all ^= (1<<(chr - 'a'));
        }
        puts("");
    }
}