#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
char s[35],t[35];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int ls=strlen(s+1),lt=strlen(t+1),now=lt,fl=1;
        for(int i=ls;i&&now;i--){
            if(s[i]==t[now]) now--;
            else{
                for(int j=1;j<=now;j++) if(t[j]==s[i]) fl=0;
            }
        }
        puts(fl&&now==0?"YES":"NO");
    }
    return 0;
}
//unordered_map