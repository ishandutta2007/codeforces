#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+100;
const ll mod = 1e9+7;
struct KMP{
    int nxt[maxn];
    int len;
    char t[maxn];
    bool border[maxn];
    void clear(){
        len =0;
        nxt[0] = nxt[1] =0;
    }
    /* 1-bas */
    /* ss\0 */
    void init(char* ss){
        len = strlen(ss+1);
        memcpy(t,ss,(len+2)*sizeof(char));
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
        int now = len;
        while (now){
            border[now] = 1;
            now = nxt[now];
        }
    }
    void debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
//            Debug(nxt[i]);
        }
    }
}kmper;
ll power(ll x,ll y){
    ll res =1;
    while (y){
        if (y &1){
            res = res * x % mod;
        }
        y >>=1;
        x = x*x %mod;
    }
    return res;
}
char s[maxn];
int pos[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);

    kmper.init(s);
    int tot =0;
    for (int i=0;i<m;i++){
        scanf("%d",pos+i);
    }
    if (m == 0){
        cout<<power(26,n);
        return 0;
    }
    tot += pos[0]-1;
    tot += n - (pos[m-1] + kmper.len) +1;
    for (int i=1;i<m;i++){
        int pre = pos[i-1];
        int now = pos[i];
        tot += max(0,now - (pre + kmper.len));
        int b_len = pre + kmper.len - 1 - now +1;
        if (b_len<=0)continue;
        if (kmper.border[b_len])continue;
        else{
            puts("0");
            return 0;
        }
    }
    cout<<power(26,tot);
    return 0;
}