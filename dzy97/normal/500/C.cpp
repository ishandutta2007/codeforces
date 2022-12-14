#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> PI;

#define REP(i, a, b) for(int i = (a);i <= (b);i ++)
#define DWN(i, a, b) for(int i = (a);i >= (b);i --)
#define CLR(a, x) memset(a, x, sizeof(a))
#define REU(i, a) for(int i = h[a];~i;i = n1[i])
#define SZ(a) ((int)(a.size()))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template <class T> inline void read(T &x){
    char ch = getchar(); int f = 1; while((ch != '-') && (ch < '0' || ch > '9')) ch = getchar();
    if(ch == '-') f = 0, x = 0; else x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    if(!f) x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x) putchar('0');
    else{
        if(x < 0) putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10) _t[++ _t[0]] = x % 10;
        for(int i = _t[0];i;i --) putchar(_t[i] + 48);
    }
    if(ln == 1) putchar('\n');
    else if(ln == 2) putchar(' ');
}

///cf

#define N 1010
int n,m,w[N],a[N],p[N],s[N],tot;
int main(){
    read(n,m);
    REP(i,1,n)read(w[i]);
    REP(i,1,m){
        read(a[i]);
        if(!p[a[i]]){
            p[a[i]]=i;
            s[++tot]=a[i];
        }
    }
    REP(i,1,n) if(!p[i]) s[++tot]=i;
    ll sum=0;
    REP(i,1,m){
        int pos;
        for(int j=1;j<=n;j++){
            if(s[j]==a[i]){
                pos=j;
                break;
            }else 
            sum+=w[s[j]];
        }
        for(int j=pos;j>=2;j--)s[j]=s[j-1];
        s[1]=a[i];
    }
    out(sum);
    return 0;
}