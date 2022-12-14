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
#define N 100010

char s[N], t[N];
int fail[N], n, m;
int f[N], g[N],h[N];
#define mo 1000000007
int l[N];

int main(){
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    fail[1] = 0;
    int k = 0;
    rep(i, 2, m){
        while(k > 0 && t[k + 1] != t[i]) k = fail[k];
        if(t[k + 1] == t[i]) k ++;
        fail[i] = k;
    }
    k = 0;
    rep(i, 1, n){
        while(k > 0 && s[i] != t[k + 1]) k = fail[k];
        if(s[i] == t[k + 1]) k ++;
        if(k == m){
            l[i] = i - m + 1;
            k = fail[k];
        }
    }
    rep(i, 1, n){
        if(l[i]){
            int j = i;
            while(j + 1 <= n && l[j + 1] == 0){
                j ++;
                l[j] = l[i];
            }
        }
    }
    f[0] = 1;
    g[0] = 1;
    rep(i, 1, n){
        if(l[i]){
            f[i] = (1LL * f[i] + 1LL * l[i] * g[l[i] - 1] - 1LL * h[l[i] - 1]) % mo;
            f[i] = (f[i] + mo) % mo;
        }
        g[i] = (g[i - 1] + f[i]) % mo;
        h[i] = (h[i - 1] + 1LL * f[i] * i) % mo;
    }
    int ans = 0;
    rep(i, 1, n) ans =(ans+f[i])%mo;
    cout << ans << endl; 
        
    return 0;
}

//f[i] = sum(f[j], [j+1]