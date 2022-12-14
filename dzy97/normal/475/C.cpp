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
int vis[2100][1100],dx[2]={1,0},dy[2]={0,1},s,t;
int n,m,l[2100],r[2100],x[4100000][2];
char gnext(){
    char ch=getchar(); while (ch!='X'&&ch!='.') ch=getchar(); return ch;
}
int Bfs(int xxx,int yyy){    x[1][0]=xxx; x[1][1]=yyy; int qqq=1,cur=0; vis[xxx][yyy]=2;
    while (qqq>cur){
        cur++;        int a=x[cur][0],b=x[cur][1]; s=min(s,a); t=max(t,a);
        l[a]=min(l[a],b); r[a]=max(r[a],b);        for (int i=0;i<=1;i++){
            int c=a+dx[i],d=b+dy[i];            if (vis[c][d]==1){
                qqq++; x[qqq][0]=c; x[qqq][1]=d; vis[c][d]=2;
            }
        }
    }
}
int valid(int kk){
    for (int i=t-kk+1;i<t;i++) if (r[i]!=r[i+1]) return -1;
    for (int i=s;i<s+kk-1;i++) if (l[i]!=l[i+1]) return -1;
    int Min=1,Max=m;    for (int i=s;i<t-kk+1;i++){        int xxx=r[i]-l[i+kk]+1;if (Min>xxx||Max<xxx) return -1;  Min=max(xxx,Min); Max=min(xxx,Max);    }
    int xxx=r[t]-l[t]+1;    if (Min>xxx) return -1;   return Min;
}
int main(){
//  freopen("data.in","r",stdin); 
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){       char ch=gnext(); if (ch=='X') vis[i][j]=1;       }
    for (int i=1;i<=n;i++){
        int flag=0;
        for (int j=1;j<=m;j++){         if (vis[i][j]==1&&flag==0) {flag=1; continue;}          if (vis[i][j]==0&&flag==1) {flag=2; continue;}          if (vis[i][j]==1&&flag==2) {cout<<-1<<endl; return 0;}
        }
    }    int num=n*m,flag=0; s=n+1;
    for (int i=1;i<=n;i++) l[i]=m+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)            if (vis[i][j]==1){                if (flag==1){cout<<"-1"<<endl; return 0;} flag=1; Bfs(i,j);
            }
    for (int i=s;i<t;i++) if (l[i+1]<l[i]||r[i+1]<r[i]){cout<<-1<<endl; return 0;}
    flag=0;
    for (int i=1;i<=n;i++){        int xxx=valid(i);        if (xxx>0){         flag=1; num=min(num,i*xxx);        }    }
    if (flag==0) printf("-1\n"); else out(num);return 0;
}