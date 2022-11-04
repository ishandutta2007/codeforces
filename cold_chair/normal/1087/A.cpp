#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

char s[55], t[105];
int n, l, r;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    l = 1, r = n;
    for(int i = n; i; i --) {
        if(i & 1) t[i] = s[l ++]; else t[i] = s[r --];
    }
    fo(i, 1, n) printf("%c", t[i]);
}