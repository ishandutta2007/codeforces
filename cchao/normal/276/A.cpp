#include <cstdio>
#include <iostream>
using namespace std;
#define F(x) (x>=0? x:0)
int main(){
    int n, k, ans = 0, f, t;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &f, &t);
        if(i==0) ans = f - F(t - k);
        else ans = max(ans, f - F(t-k));
    }
    printf("%d\n", ans);
    return 0;
}