#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
int n,m,h;
int ans[maxn][maxn];
int front[maxn];
int left[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&h);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ans[i][j] = INT_MAX;
        }
    }
    for (int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);
        for (int j=0;j<n;j++){
            ans[j][i] = min(ans[j][i],temp);
        }
    }
    for (int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        for (int j=0;j<m;j++){
            ans[i][j] = min(ans[i][j],temp);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int temp;
            scanf("%d",&temp);
            if (temp == 0)ans[i][j] = 0;
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}