#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[1000100];
int h[200000], m[200000];
int sh = 0, sm=0;
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
        if(strncmp(s+i, "heavy", 5)==0)
            h[sh++] = i;
        else if(strncmp(s+i, "metal", 5) == 0)
            m[sm++] = i;
    int j = 0;
    long long ans = 0;
    for(int i = 0; i < sh; ++i) {
        while(j < sm && h[i] > m[j]) ++j;
        ans = ans + (sm - j);
    }
    cout << ans << endl;
    return 0;
}