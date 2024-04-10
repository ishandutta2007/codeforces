#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];
int lasta[N], lastb[N];

int main(){
    int n, m, ka, kb;
    scanf("%d%d%d%d", &n, &m, &ka, &kb);
    for (int i = 0; i < ka; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < kb; ++ i){
        scanf("%d", &b[i]);
    }
    if (ka > m - 1 || kb > n - 1){
        puts("No");
        return 0;
    }
    puts("Yes");
    while (ka < m - 1){
        a[ka ++] = 1;
    }
    while (kb < n - 1){
        b[kb ++] = n + 1;
    }
    std::set <int> set;
    for (int i = 1; i <= n + m; ++ i){
        set.insert(i);
    }
    for (int i = 0; i < m - 1; ++ i){
        set.erase(a[i]);
        lasta[a[i]] = i;
    }
    for (int i = 0; i < n - 1; ++ i){
        set.erase(b[i]);
        lastb[b[i]] = i;
    }
    int nowa = 0, nowb = 0;
    for (int i = 0; i < n + m - 2; ++ i){
        auto u = set.begin();
        int x = *u;
        set.erase(u);
        if (x <= n){
            printf("%d %d\n", x, b[nowb]);
            if (nowb == lastb[b[nowb]]){
                set.insert(b[nowb]);
            }
            ++ nowb;
        }
        else{
            printf("%d %d\n", x, a[nowa]);
            if (nowa == lasta[a[nowa]]){
                set.insert(a[nowa]);
            }
            ++ nowa;
        }
    }
    auto u = set.begin();
    int x = *u;
    ++ u;
    printf("%d %d\n", x, *u);
    return 0;
}

/*
4 5 4 2
1 3 3 4
7 8

4 3 3 1
3 2 2
6
 */