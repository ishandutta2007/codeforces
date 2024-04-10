#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
char s[maxn];
int n;
int main(){
    scanf("%d%s",&n,s);
    if (n&1){
        return puts(":("),0;
    }
    int nn = n/2;
    int cntl = nn,cntr = nn;
    for (int i=0;i<n;i++){
        if (s[i] != '?'){
            cntl -= s[i] == '(';
            cntr -= s[i] == ')';
        }
    }
    if (cntl<0 || cntr<0)return puts(":("),0;
    for (int i=0;i<n;i++){
        if (s[i] == '?'){
            if (cntl){
                s[i] = '(';
                cntl--;
            }else{
                s[i] = ')';
                cntr --;
            }
        }
    }
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += s[i] == '('?1:-1;
        if (i != n-1 && sum <=0 || i == n-1 && sum != 0){
            return puts(":("),0;
        }
    }
    puts(s);
    return 0;
}