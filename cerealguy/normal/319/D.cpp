#include <cstring>
#include <cstdio>

char s[50216];
int next[50216];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        next[i] = i+1;
    }
    int stringLength = n;
    for (int length = 1; 2*length <= stringLength; length++) {
        int l0 = 0;
        int l1 = 0;
        for (int it = 0; it < length; it++) l1 = next[l1];
        int r0 = l0;
        int r1 = l1;
        int curMatch = 0;
        
        int left = stringLength-2*length;
        while (left>=0) {
            while (s[r0] == s[r1]) {
                ++curMatch; 
                if (curMatch == length) {
                    next[r0] = next[r1];
                    r0 = l0;
                    l1 = next[r1];
                    r1 = next[r1];
                    curMatch = 0;
                    stringLength -= length;
                    left -= length;
                } else {
                    r0 = next[r0];
                    r1 = next[r1];
                }
            }
            l0 = next[l0];
            l1 = next[l1];
            if (--curMatch<0) {
                curMatch = 0;
                r0 = l0;
                r1 = l1;
            }
            --left;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i = next[i]) {
        s[cnt++] = s[i];
    }
    s[cnt++] = 0;
    printf("%s\n", s);
}