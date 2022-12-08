#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, k;
int arr[102];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        while(k--){
            int pnt = 1;
            while(pnt <= n && !arr[pnt]) pnt++;
            if(pnt == n+1) break;
            arr[pnt]--;
            arr[n]++;
        }
        for(int i=1; i<=n; i++) printf("%d ", arr[i]);
        puts("");
    }
}