#include<bits/stdc++.h>
using namespace std;
long long d[1000][1000];
int my_sqrt(long long x){
    return (int)sqrt((long double)x+1e-12);
}
int main() {
    int n;
    string s;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) scanf("%lld", &d[i][j]);
    for(int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        while(x == i) x++;
        while(y == i || y == x) y++;
        printf("%d ", my_sqrt(d[i][x] * d[i][y] / d[x][y]));
    }
    return 0;
}