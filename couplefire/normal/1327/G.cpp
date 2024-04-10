#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 4e5 + 50;
int ch[maxn][15], fail[maxn];
ll cost[maxn], rt, tot = 0;
void ins(char *s, int val){
    int p = rt;
    while(*s){
        int x = *s - 'a';
        if(!ch[p][x]) {
            ch[p][x] = ++tot;
        }
        p = ch[p][x];
        s++;
    }
    cost[p] += val;
}
queue<int> q;
void get_fail()
{
    while(q.size()) q.pop();
    for(int i = 0; i < 15; ++i)
        if(ch[rt][i]) q.push(ch[rt][i]), fail[ch[rt][i]] = rt;
        else ch[rt][i] = rt;
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < 15; ++i){
            if(ch[cur][i]) {
                fail[ ch[cur][i] ] = ch[ fail[cur] ][i];
                q.push(ch[cur][i]);
                cost[ch[cur][i]] += cost[ fail[ ch[cur][i] ] ];
            }
            else ch[cur][i] = ch[fail[cur]][i];
        }
    }
}
char t[1050];
void init(){
    tot = 0; rt = ++tot;
    int n; scanf("%d", &n);
    fors(i, 0, n){
        int x;
        scanf("%s%d", t, &x); ins(t, x);
    }
    get_fail();
}
char s[maxn];
int pos[20], cnt = 0;
int nxt[1050][17];
ll sum[1050][17];
ll dp[1050][1<<14];
int cal(int x){int res = 0; while(x) res++, x-=lowbit(x); return res;}
void sol(){
    scanf("%s", s);
    int n = strlen(s);
    pos[cnt++] = -1;
    fors(i, 0, n) if(s[i] == '?') pos[cnt++] = i;
    pos[cnt] = n;
    fors(i, 0, cnt){
        fors(u, 1, tot+1){
            int p = u;
            fors(j, pos[i]+1, pos[i+1]){
                p = ch[p][s[j]-'a'];
                sum[u][i] += cost[p];
            }nxt[u][i] = p;
        }
    }
    memset(dp, 0xcf, sizeof dp);
    dp[nxt[rt][0]][0] = sum[rt][0];
    ll ans = -1e18;
    if(cnt == 1) ans = sum[rt][0];//if there is no "?"
    fors(mask, 1, (1<<14)){
        int num = cal(mask);
        if(num > cnt-1) continue;
        fors(u, 1, tot+1){
            fors(i, 0, 14){
                if(mask>>i&1){
                    dp[ nxt[ch[u][i]][num] ][mask] =
                    max(dp[ nxt[ch[u][i]][num] ][mask], dp[u][mask^(1<<i)]+cost[ch[u][i]]+sum[ch[u][i]][num]);
                    if(num == cnt-1) {
                        ans = max(ans, dp[ nxt[ch[u][i]][num] ][mask]);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    init();
    sol();
}