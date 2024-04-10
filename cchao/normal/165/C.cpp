#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
char s[1000010];
long long pos[1000010];
int len, sz=0;
long long f(long long x){
//  if(x==0) return 1;
    return x*(x+1)/2;
}
int main(){
    long long ans = 0;
    int a, b;
    scanf("%d%s", &n, s);
    len = strlen(s);
    if(n==0){
        int cnt = 0;
        for(int i = 0; i < len; ++i)
            if(s[i]=='0'){
                ++cnt;
            }
            else{
                ans += f(cnt);
                cnt = 0;
            }
        ans += f(cnt);
        cout << ans << endl;
        return 0;
    }
    for(int i = 0; s[i]; ++i){
        if(s[i] == '1') pos[sz++] = i;
    }
    a = 0, b = n-1;
    while(b<sz){
        long long left, right;
        left = a ? pos[a] - pos[a-1] : pos[a] + 1;
        right = b+1 < sz ? pos[b+1] - pos[b] : len - pos[b];
        ans += left * right;
        b++;a++;
    }
    cout << ans << endl;
    return 0;
}