#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, k;
bool arr[52];
int ans;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        ans = 0;
        for(int i=1; i<=n; i++){
            char c;
            scanf(" %c", &c);
            if(c=='*') arr[i] = 1;
            else arr[i] = 0;
        }

        int s=-1, e=-1;
        for(int i=1; i<=n; i++){
            if(arr[i]){
                s = i;
                break;
            }
        }
        for(int i=n; i>=1; i--){
            if(arr[i]){
                e = i;
                break;
            }
        }
        if(s==-1){
            puts("0");
            continue;
        }
        if(s==e){
            puts("1");
            continue;
        }
        ans = 2;
        int dist = 1, last = s;
        for(int i=s+1; i<e; i++){
            if(arr[i]) last = i;
            if(dist == k){
                dist = i - last;
                ans++;
            }
            dist++;
        }
        printf("%d\n", ans);
    }
}