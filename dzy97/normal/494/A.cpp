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

char str[100010]; 
int an[100010], antot = 0;
int main(){
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    int cnt = 0; 
    for(int i = 1;i <= n;i ++) if(str[i] == '#') cnt ++;
    int tmp = 0;
    for(int i = 1;i <= n;i ++){
        if(str[i] == '#'){
            ++ tmp;
            if(tmp < cnt) str[i] = ')';
        }
    }
    int sum = 0, rsum = 0;
    for(int i = n;i >= 1;i --){
        if(str[i] == '(') rsum ++;
        else if(str[i] == ')') rsum--;
        else break;
    }
    for(int i=1;i<=n;i++){
        if(str[i]=='(')sum++;
        else if(str[i]==')')sum--;
        else break;
    }
    if(sum + rsum <= 0){
        cout << -1 << endl;
        return 0;
    }
    int num = sum + rsum;
    sum = 0;
    for(int i=1;i<=n;i++){
        if(str[i] == '(') sum ++;
        else if(str[i] ==')') sum --;
        else sum -= num;
        if(sum < 0){
            cout <<-1<<endl;
            return 0;
        }
    }
    rep(i,1,cnt-1)out(1);
    out(num);
    return 0;
}