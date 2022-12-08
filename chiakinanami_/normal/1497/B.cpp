#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, m;
int arr[100002];
int cnt[100002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            arr[i] %= m;
        }

        for(int i=1; i<=n; i++){
            cnt[arr[i]]++;
        }
        int ans = 0;
        for(int i=0; i*2<=m; i++){
            if(i==0 || i*2==m){
                ans += !!cnt[i];
            }
            else{
                if(!cnt[i] && !cnt[m-i]) continue;
                int tmp = max(cnt[i], cnt[m-i]) - min(cnt[i], cnt[m-i]);
                ans += max(tmp, 1);
            }
        }
        printf("%d\n", ans);

        for(int i=1; i<=n; i++) cnt[arr[i]]--;
    }
}