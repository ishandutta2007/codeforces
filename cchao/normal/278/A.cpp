#include <cstdio>
#include <iostream>

using namespace std;
int n;
void next(int &x){++x; if(x==n+1)x=1;}
int main(){
    int d[110], s, t, sum=0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &d[i]), sum += d[i];
    scanf("%d%d", &s, &t);

    int tmp = 0;
    for(int i = s; i!=t; next(i))
        tmp += d[i];
    printf("%d\n", min(tmp, sum-tmp));
    return 0;
}