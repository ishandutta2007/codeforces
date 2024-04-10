#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int sum[maxn];
int prefix_min[maxn],suffix_min[maxn];
char s[maxn];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    prefix_min[0] = suffix_min[n+1] = 0x3f3f3f3f;
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1];
        if (s[i] == '(')sum[i] ++;
        else sum[i] --;
        prefix_min[i] = min(prefix_min[i-1],sum[i]);
    }
    for (int i=n;i>=1;i--){
        suffix_min[i] = min(suffix_min[i+1],sum[i]);
    }
    if (abs(sum[n]) != 2){
        puts("0");
        return 0;
    }
    prefix_min[0] = suffix_min[n+1] = 2;
    char tar = '(';
    if (sum[n] < 0)tar = ')';
    int ans =0;
    for (int i=1;i<=n;i++){
        if (s[i] != tar || i == 1 && s[i] == '(' || i == n && s[i] == ')')continue;
        int min1 = prefix_min[i-1];
        int min2 = suffix_min[i+1];
        if (tar == '('){
            ans += min1 >= 0 && sum[i-1] >=1 && min2 >= 2;
        }else{
            ans += min1 >= 0  && min2 >=-2;
        }
    }
    cout<<ans<<endl;
    return 0;
}