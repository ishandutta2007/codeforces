#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q, n, m;
char arr[502];
char query[1002];

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%s %s", arr+1, query+1);
        n = strlen(arr+1), m = strlen(query+1);
        bool yes = 0;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(m > (j-i) + j) continue;
                bool able = 1;
                int pnt = 1;
                for(int k=i; k<=j; k++){
                    if(arr[k] != query[pnt++]){
                        able = 0;
                        break;
                    }
                }
                for(int k=j-1; k>=0 && pnt<=m; k--){
                    if(arr[k] != query[pnt++]){
                        able = 0;
                        break;
                    }
                }
                if(able){
                    yes = 1;
                    break;
                }
            }
        }
        printf("%s\n", yes ? "YES" : "NO");
    }
}