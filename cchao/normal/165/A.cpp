#include <cstdio>
#include <set>
using namespace std;
int n, x[200], y[200];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int a[4]={0};
        for(int j = 0; j < n; ++j){
            if(j==i) continue;
            if(x[i]==x[j] && y[i] > y[j]) a[0]=1;
            if(x[i]==x[j] && y[i] < y[j]) a[1]=1;
            if(x[i]>x[j] && y[i] == y[j]) a[2]=1;
            if(x[i]<x[j] && y[i] == y[j]) a[3]=1;
        }
        if(a[0] + a[1] + a[2] + a[3] == 4)  ans++;
    }
    printf("%d\n", ans);
    return 0;
}