#include <cstdio>

int n, m;
char park[2001];
int count[2000];

int main() {
    scanf("%d%d%*d", &n, &m);
    getchar();
    
    fread(park, sizeof(char), m + 1, stdin);
    for(int r = 1; r < n; ++r) {
        fread(park, sizeof(char), m + 1, stdin);
        for(int c = 0; c < m; ++c) {
            if(c - r >= 0 && park[c - r] == 'R') ++count[c];
            if(c + r < m && park[c + r] == 'L') ++count[c];
            if(r % 2 == 0 && park[c] == 'U') ++count[c];
        }
    }
    for(int c = 0; c < m; ++c) {
        printf("%d ", count[c]);
    }
}