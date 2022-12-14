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
int gcd(int a,int b){
    return (!b) ? a : gcd(b,a%b);
}
#define N 100010
int st[N],l[N],r[N],v[N],top = 0,re[N],ptot = 0,tot = 0,n,a[N];
int p1[N],n1[N],T; 
int gn(){
    if(ptot)    return re[ptot --];
    else        return ++ tot;
}
void add(int x,int w){
    int k = T;
    ++ top;
    p1[top] = k;
    n1[k] = top;
    l[top] = r[top] = x;
    v[top] = w;
}
map<int,ll> cnt;
void work(){
    int x = top;
//  cout << top <<" "<<v[top]<<endl; 
    while(p1[x]){
        if(v[x] % v[p1[x]]) v[p1[x]] = gcd(v[x],v[p1[x]]);
    //  cout << v[x]<<" "<<v[p1[x]]<<endl; 
        x = p1[x];
    }   
    x = n1[0];
    while(x){
        T = x; 
    //  cout <<v[x]<<" "<<v[n1[x]]<<endl; 
        if(v[x] == v[n1[x]]){
            l[x] = l[n1[x]];
        //  cout << v[n1[n1[x]]]<<endl;
            p1[n1[n1[x]]] = x;
            n1[x] = n1[n1[x]];
        }
        x = n1[x];
    }   
    for(int i=n1[0];i;i=n1[i])cnt[v[i]]+=r[i]-l[i]+1;//cout <<l[i]<<" "<<r[i]<<" "<<v[i]<<endl; 
}
int main(){
    read(n);
    rep(i,1,n)  read(a[i]);
    dwn(i,n,1){
        add(i,a[i]);
        work();
    }
    int q,x;
    read(q);
    rep(i,1,q)read(x),out(cnt[x]); 
    return 0;
}