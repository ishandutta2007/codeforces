#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[102];
int gcd;

bool DP[102][800002];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    gcd = arr[1];
    for(int i=1; i<=n; i++) gcd = __gcd(gcd, arr[i]);
    for(int i=1; i<=n; i++) arr[i] /= gcd;

    if(accumulate(arr+1, arr+n+1, 0) % 2) printf("0");
    else{
        DP[0][400000] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=800000; j++){
                if(!DP[i-1][j]) continue;
                DP[i][j-arr[i]] = DP[i][j+arr[i]] = 1;
            }
        }
        if(!DP[n][400000]){
            printf("0");
            return 0;
        }

        int pnt = 1;
        while(arr[pnt] % 2 == 0) pnt++;
        printf("1\n%d\n", pnt);
    }
}