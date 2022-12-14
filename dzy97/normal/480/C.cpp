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


/*...........................................................................................................*/

int N,A,B,K;
#define mo 1000000007
int f[5010],tag[5010];

int main(){
    read(N);
    read(A);
    read(B);
    read(K);
    f[A] = 1;
    rep(i,1,K){
        clr(tag,0);
        rep(j,1,N){
            if(!f[j])   continue;
            int x = abs(j - B);
            int l = max(1,j - x + 1), r = min(N, j + x - 1);
            if(l <= j - 1){
                tag[l] += f[j];
                if(tag[l] >= mo)    tag[l] -= mo;
                tag[j] += mo - f[j];
                if(tag[j] >= mo)    tag[j] -= mo;
            }
            if(j + 1 <= r){ 
                tag[j + 1] += f[j];
                if(tag[j + 1] >= mo)    tag[j + 1] -= mo;
                tag[r + 1] += mo - f[j];
                if(tag[r + 1] >= mo)    tag[r + 1] -= mo;
            }
        }
        rep(j,1,N){
            tag[j] += tag[j - 1];
            if(tag[j] >= mo)    tag[j] -= mo;
            f[j] = tag[j];
        }
    }
    int ans = 0;
    rep(i,1,N)  if(i != B){
        ans += f[i];
        if(ans >= mo)   ans -= mo;
    }
    cout << ans << endl;
    return 0;
}