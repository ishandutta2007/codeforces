#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[2002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        int allXOR = 0;
        for(int i=1; i<=n; i++) allXOR ^= arr[i];
        if(allXOR == 0){
            printf("YES\n");
            continue;
        }

        int partialXOR = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            partialXOR ^= arr[i];
            if(partialXOR == allXOR){
                partialXOR = 0;
                cnt++;
            }
        }
        printf("%s\n", cnt >= 2 ? "YES" : "NO");
    }
}