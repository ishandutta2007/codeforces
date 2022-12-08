#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, m;
char a[25], b[25];
int ans;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s %s", a+1, b+1);
        n = strlen(a+1), m = strlen(b+1);

        ans = 0;
        for(int d=1; d<=n && d<=m; d++){
            for(int i=1; i+d-1<=n; i++){
                for(int j=1; j+d-1<=m; j++){
                    bool good = 1;
                    for(int x=i, y=j; x<=i+d-1; x++, y++){
                        if(a[x] != b[y]){
                            good = 0;
                            break;
                        }
                    }
                    if(good) ans = max(ans, d);
                }
            }
        }
        printf("%d\n", n + m - 2*ans);
    }
}