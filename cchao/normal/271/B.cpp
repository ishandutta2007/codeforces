#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int arr[510][510], cost[510][510], np[100010]={0}, p[100000], sz=0, a1, a2, tmp;
int main(){
    a1 = a2 = 1000000000;
    int n, m;
    np[0] = np[1] = 1;
    for(int i = 2; i <= 100010; ++i){
        if(np[i]==0){
            p[sz++] = i;
            for(int j = i*2; j<=100010; j+=i)
                np[j]=1;
        }
    }
//  printf("%d %d\n", sz, p[sz-1]);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        tmp = 0;
        for(int j = 0; j < m; ++j){
            scanf("%d", &arr[i][j]);
            int a = lower_bound(p, p+sz, arr[i][j]) - p;
            cost[i][j] = abs(p[a] - arr[i][j]);
            tmp += cost[i][j];
        }
        a1 = min(a1, tmp);
    }
    for(int j = 0; j < m; ++j){
        tmp = 0;
        for(int i = 0; i < n; ++i){
            tmp += cost[i][j];
        }
        a2 = min(a2, tmp);
    }
    printf("%d\n" ,min(a1, a2));
    return 0;
}