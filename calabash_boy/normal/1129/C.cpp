#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000+10;
const int N = maxn * maxn * 2;
const int MOD = 1e9+7;
struct Trie{
    const int Root = 1;
    int cnt = 2;
    int nxt[N][2];
    int add(const int *a,int n){
        int temp = Root;
        int res = -1;
        for (int i=n;i>=1;i--){
            int ch = a[i];
            if (!nxt[temp][ch]){
                if (res == -1)res = i;
                nxt[temp][ch] = cnt++;
            }
            temp = nxt[temp][ch];
        }
        assert(res != -1);
        return res;
    }
}trie;
int s[maxn];
int m;
int dp[maxn][maxn];
int check(int pos,int len){
    if (pos < len)return false;
    if (len <=3 )return true;
    if (s[pos] == 0){
        if(s[pos-1] == 1 and s[pos-2] == 1 and s[pos-3] == 1)return false;
        return true;
    }else if (s[pos-1] == 0){
        if (s[pos-2] == 1 and s[pos-3] == 0)return false;
        return true;
    }else{
        if (s[pos-2] == 0 and s[pos-3] == 0)return false;
        if (s[pos-2] == 1 and s[pos-3] == 1)return false;
        return true;
    }
}
int main(){
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",s+i);
    }
    for (int i=1;i<=m;i++){
        dp[i][i-1] = 1;
    }
    for (int i=1;i<=m;i++){
        for (int j=i;j<=m;j++){
            int last = min(4,j-i+1);
            for (int len = 1;len <=last;len ++){
                if (check(j,len)){
                    (dp[i][j] += dp[i][j-len])%= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i=1;i<=m;i++){
        int right = trie.add(s,i);
        //printf("i = %d, right = %d\n",i,right);
        for (int len=1;len<=4;len++){
            if (check(i,len)){
                for (int x = 1;x <= right;x ++){
                    (ans += dp[x][i-len]) %= MOD;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}