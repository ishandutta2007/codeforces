#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn];
typedef long long ll;
ll dp[maxn];
int main(){
    int ans = 0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (i && a[i] == a[i-1]){
            puts("Infinite");
            return 0;
        }
    }
    for (int i=1;i<n;i++){
        int x = a[i];
        int y = a[i-1];
        if (x == 1 && y == 2){
            ans += 3;
        }else if (x == 1 && y == 3){
            ans += 4;
        }else if (x == 2 && y ==1){
            ans += 3;
        }else if (x == 2 && y == 3){
            puts("Infinite");
            return 0;
        }else if (x == 3 && y == 1){
            ans += 4;
        }else if (x == 3 && y == 2){
            puts("Infinite");
            return 0;
        }
    }
    for (int i=2;i<n;i++){
        int x1 = a[i-2];
        int x2 = a[i-1];
        int x3 = a[i];
        ans -= (x1 == 3 && x2 == 1 && x3 == 2);
    }
    puts("Finite");
    cout<<ans<<endl;
    return 0;
}