#include<bits/stdc++.h>

const int N = 40;
const int INF = 1e9;

bool col[N];
char s[N];

bool ask(int x, int y){
    printf("%d %d\n", x, y);
    fflush(stdout);
    scanf("%s", s);
    return !strcmp(s, "black");
}

int main(){
    int n;
    scanf("%d", &n);
    col[0] = ask(0, 0);
    if (n == 1){
        puts("1 0 1 1");
        return 0;
    }
    col[1] = ask(INF, INF);
    int left = 0, right = INF;
    for (int i = 2; i < n; ++ i){
        int mid = left + right >> 1;
        if (ask(mid, 0) == col[0]){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    int mid = left + right >> 1;
    if (col[0] == col[1]){
        printf("%d %d %d %d\n", mid, 0, mid + 1, 1);
    }
    else{
        printf("%d %d %d %d\n", mid, 0, mid, 1);
    }
    return 0;
}