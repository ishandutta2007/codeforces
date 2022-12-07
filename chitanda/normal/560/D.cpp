#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define M 1000000007
#define ll unsigned long long

const int N = 200100;
ll p[N], q[N], pp[N], qq[N];
int n, k, len;
char s1[N], s2[N];

bool work(){
    for(int i = k; i; i--, n >>= 1){
        memcpy(pp, p, (n + 1) * 8);
        memcpy(qq, q, (n + 1) * 8);
        sort(pp + 1, pp + n + 1);
        sort(qq + 1, qq + n + 1);
        for(int j = 1; j <= n; j++) if (pp[j] != qq[j]) return 0;
        for(int j = 1; j <= (n >> 1); j++){
            p[j] = (min(p[j * 2 - 1], p[j * 2]) * (M - 1) + max(p[j * 2 - 1], p[j * 2])) % M;
            q[j] = (min(q[j * 2 - 1], q[j * 2]) * (M - 1) + max(q[j * 2 - 1], q[j * 2])) % M;
        }
    }
    return 1;   
}

int main(){
    cin >> s1; cin >> s2;
    len = strlen(s1); n = 1; k = 1;
    while (len % 2 == 0) n *= 2,  len >>= 1, k++;
    for(int i = 1, now = 0; i <= n; i++, now += len)
        for(int j = 1; j <= len; j++)
            p[i] = p[i] * 271 + s1[now + j - 1], q[i] = q[i] * 271 + s2[now + j - 1];
    
    if (work()) printf("YES"); else printf("NO");
    return 0;
}