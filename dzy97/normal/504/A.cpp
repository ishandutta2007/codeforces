#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;

#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define rep1(i,a,b) for(int i = (a);i < (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define dwn1(i,a,b) for(int i = (a);i > (b);i --)
#define rev(i,a) for(int i = 0;i < a.size();i ++)
#define reu(i,a) for(int i = h[a];~i;i = n1[i])

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
    if(ln == 2) putchar(' ');
    else    if(ln == 1) putchar('\n');
}

#define N 70000
struct node{
    int d, s, id;
}a[N],b[N];
pr ee[N*30];
int etot,vis[N];

int cmp(const node &a, const node &b){
    return a.d < b.d;
}
int n, q[N];
int main(){
    read(n);
    int s=1,e=0;
    for(int i = 0;i < n;i ++){
        read(a[i].d, a[i].s), a[i].id = i;
        if(a[i].d == 1){
            q[++e] = i;
            vis[i]=1;
        }
    }
    
    while(s <=e){
        int u=q[s++];
        if(a[u].d==1){
            ee[++ etot]=mp(a[u].id,a[u].s);
                a[a[u].s].s^=a[u].id;
            if(--a[a[u].s].d==1){
                q[++e]=a[u].s;
                vis[a[u].s]=1;
            }
        }
    }
    
    out(etot);
    rep(i,1,etot) printf("%d %d\n", ee[i].first,ee[i].second); 
    return 0;
}