#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
char s[maxn];
int sum[maxn];
int n;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    int pre_0 = 0;
    int ans = 0;
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1] + (s[i] == '('?1 : -1);
        if (sum[i] == 0 and sum[i-1] < 0){
            ans += i - pre_0 ;
        }
        if (sum[i] == 0)pre_0 = i;
    }
    if (sum[n] == 0){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}