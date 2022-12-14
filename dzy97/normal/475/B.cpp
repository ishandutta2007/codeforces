#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

typedef long long ll;
typedef long double db;

template <class T> inline void read(T &x){
    char ch = getchar();    int f = 1;  while((ch != '-') && (ch < '0' || ch > '9'))    ch = getchar();
    if(ch == '-')   f = 0, x = 0;   else    x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9')   x = x * 10 + ch - 48, ch = getchar();
    if(!f)  x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x)  putchar('0');
    else{
        if(x < 0)   putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10)    _t[++ _t[0]] = x % 10;
        dwn(i,_t[0],1)  putchar(_t[i] + 48);
    }
    if(ln)  putchar('\n');
}

/*...........................................................................................................*/

#define N 600
int p[200000],n1[200000],h[100000],ee=0;
int id[25][25],vis[N];
char s[40],t[40];
int n,m;
void ae(int x,int y){
    p[ee]=y;n1[ee]=h[x];h[x]=ee++;
}
void dfs(int u){
    vis[u]=1;
    reu(i,u)if(!vis[p[i]])  dfs(p[i]);
}
int main(){
    clr(h,-1);
    read(n,m);
    int tot=(n)*(m);
    int cnt=0;
    rep(i,1,n)rep(j,1,m)id[i][j]=++cnt;
    scanf("%s",s+1);
    scanf("%s",t+1);
    rep(i,1,n)  rep(j,1,m-1)    if(s[i]=='>')   ae(id[i][j],id[i][j+1]);    else    ae(id[i][j+1],id[i][j]);
    rep(j,1,m)  rep(i,1,n-1)    if(t[j]=='v')   ae(id[i][j],id[i+1][j]);    else    ae(id[i+1][j],id[i][j]);
    rep(i,1,tot){
        rep(j,1,tot)vis[j]=0;
        dfs(i);
        rep(j,1,tot)if(!vis[j]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}