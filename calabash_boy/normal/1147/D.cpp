#include <bits/stdc++.h>
using namespace std;
const int maxn =  4000 + 50;
const int mod = 998244353;
int pow2[maxn];
int ans = 0;
int n;
int fa[maxn];
int find(int x){
    return fa[x] == x?x : fa[x] = find(fa[x]);
}
void merge(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if (fu == fv)return;
    fa[fu] = fv;
}
bool check(int u,int v){
    int fu = find(u);
    int fv = find(v);
    return fu == fv;
}
int id_b[maxn][2];
int id_a[maxn][2];
int tot = 1;
char s[maxn];
bool used[maxn];
void gao(int a_first){
  //  cerr<<a_first<<endl;
    for (int i=1;i<=tot;i++){
        fa[i] = i;
    }
    for (int i=1;i<=n;i++){
        merge(id_b[i][0],id_b[n+1-i][0]);
        merge(id_b[i][1],id_b[n+1-i][1]);
    }
    for (int i=a_first;i<=n;i++){
        merge(id_a[i][0],id_a[a_first + n - i][0]);
        merge(id_a[i][1],id_a[a_first + n - i][1]);
    }
    for (int i=1;i<=n;i++){
        if (s[i] == '1'){
            merge(id_a[i][0],id_b[i][1]);
            merge(id_a[i][1],id_b[i][0]);
        }else if (s[i] == '0'){
            merge(id_a[i][0],id_b[i][0]);
            merge(id_a[i][1],id_b[i][1]);
        }
    }
    for (int i=1;i<=n;i++){
        if (check(id_a[i][0],id_a[i][1]))return;
        if (check(id_b[i][0],id_b[i][1]))return;
    }
    memset(used,0,sizeof used);
    used[find(id_b[1][1])] = 1;
    used[find(id_a[a_first][1])] = 1;
    for (int i=1;i<a_first;i++){
        used[find(id_a[i][0])] = 1;
    }
    for (int i=1;i<=n;i++){
        //  cerr<<"find b"<<i<<" "<<find(id_b[i][0]) <<" " << find(id_b[i][1])<<endl;
        //  cerr<<"find a"<<i<<" "<<find(id_a[i][0]) <<" " << find(id_a[i][1])<<endl;
        if (used[find(id_a[i][0])] && used[find(id_a[i][1])])return;
        if (used[find(id_b[i][0])] && used[find(id_b[i][1])])return;
    }
    //cerr<<find(id_b[1][1])<<endl;
    //cerr<<find(id_a[1][0])<<endl;
    //cerr<<find(id_a[2][1])<<endl;

    int cnt = 0;
    for (int i=1;i<=tot;i++){
        if (i == find(i)){
            if (!used[i])cnt ++;
            else cnt --;
        }
    }
   // cerr<<a_first<<" "<<cnt<<endl;
    //cerr<<a_first<<endl;
    assert(cnt % 2 == 0);
    (ans += pow2[cnt/2]) %= mod;
}
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    pow2[0] = 1;
    for (int i=1;i<maxn;i++){
        pow2[i] = pow2[i-1] * 2 % mod;
    }
    for (int i=1;i<=n;i++){
        id_a[i][0] = tot ++;
        id_a[i][1] = tot ++;
        id_b[i][0] = tot ++;
        id_b[i][1] = tot ++;
    }
    tot --;
    for (int i=2;i<=n;i++){
        gao(i);
    }
    printf("%d\n",ans);
    return 0;
}