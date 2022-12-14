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
    if(x < 0)   putchar('-'),x = -x;
    for(_t[0] = 0;x;x /= 10)    _t[++ _t[0]] = x % 10;
    dwn(i,_t[0],1)  putchar(_t[i] + 48);
    if(ln)  putchar('\n');
}

/*...........................................................................................................*/

int n,L,X,Y;
#define N 100010
int a[N];
map <int,int> s,xx;
int main(){
    read(n,L,X,Y);
    rep(i,1,n)  read(a[i]),s[a[i]] = 1;
    int fx = 0, fy = 0;
    rep(i,1,n){
        if(s[a[i]+X])   fx = 1;
        if(s[a[i]+Y])   fy = 1;
        xx[a[i]-X] |=1;
        xx[a[i]-Y] |=2;
        xx[a[i]+X] |=1;
        xx[a[i]+Y] |=2;     
    }
    if(fx && fy){
        printf("0\n");
        return 0;
    }
    for(map<int,int>::iterator it=xx.begin();it !=xx.end();it ++){
        if(((it->first)>=0 && (it->first)<=L) && ((it->second)|(fx)|(2*fy)) == 3){
            printf("%d\n%d\n",1,it->first);
            return 0;
        }
    }
    printf("%d\n%d %d\n",2,X,Y); 
    return 0;
}