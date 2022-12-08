#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[102];
int cnt[102];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        fill(cnt, cnt+101, 0);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
        }
        int pnt = 1;
        for(int i=0; i<=100; i++){
            if(cnt[i]){
                arr[pnt++] = i;
                cnt[i]--;
            }
        }
        for(int i=0; i<=100; i++){
            while(cnt[i]--){
                arr[pnt++] = i;
            }
        }

        for(int i=1; i<=n; i++){
            printf("%d ", arr[i]);
        }
        puts("");
    }
}