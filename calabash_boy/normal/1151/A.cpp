#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
char s[maxn];
int n;
inline int cost(char x,char y){
    int t = abs(y-x);
    return min(t,26 - t);
}
char t[] = "ACTG";
int calc(int st){
    int ans = 0;
    for (int i=0;i<4;i++){
        ans += cost(s[st+i],t[i]);
    }
    return ans;
}
int main(){
    scanf("%d%s",&n,&s);
    int ans = INT_MAX;
    for (int i=0;i<=n-4;i++){
        ans = min(ans,calc(i));
    }
    cout<<ans<<endl;
    return 0;
}