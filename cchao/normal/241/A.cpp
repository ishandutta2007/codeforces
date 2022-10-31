#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int d[1000], s[1000];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &d[i]);
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);
    int now = 0, fuel = s[0], ans = 0, best_station = 0;
    while(now < n){
        //printf("in %d fuel %d\n", now, fuel);
        if(s[now] > s[best_station])
            best_station = now;
        if(fuel < d[now]){
            fuel += s[best_station];
            ans += m;
        }
        else{
            fuel -= d[now];
            ans += d[now];
            now++;
            fuel += s[now];
        }
    }
    printf("%d\n", ans);
    return 0;
}