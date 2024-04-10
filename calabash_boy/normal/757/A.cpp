#include <cstring> 
#include <cstdlib> 
#include <iostream> 
#include <algorithm> 
#include<stdio.h>
#include <set>
#include <stack> 
#include <queue> 
#include <vector> 
#include <map>
#define pb push_back
#define lb lower_bound
#define sqr(x) (x)*(x)
#define lowbit(x) (x)&(-x) 
#define Abs(x) ((x) > 0 ? (x) : (-(x))) 
#define FOR(i,a,b) for((i)=(a);(i)<=(b);(i)++) 
#define FORP(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORM(i,a,b) for(int i=(a);i>=(b);i--) 
#define ls(a,b) (((a)+(b)) << 1) 
#define rs(a,b) (((a)+(b)) >> 1) 
#define getlc(a) ch[(a)][0] 
#define getrc(a) ch[(a)][1] 
 
#define maxn 100005
#define maxm 100005
#define INF 1070000000 
using namespace std; 
typedef long long ll; 
typedef unsigned long long ull; 
 
template<class T> inline 
void read(T& num){ 
    num = 0; bool f = true;char ch = getchar(); 
    while(ch < '0' || ch > '9') { if(ch == '-') f = false;ch = getchar();} 
    while(ch >= '0' && ch <= '9') {num = num * 10 + ch - '0';ch = getchar();} 
    num = f ? num: -num; 
}
int out[100];
template<class T> inline
void write(T x,char ch){
if (x==0) {putchar('0'); putchar(ch); return;}
if (x<0) {putchar('-'); x=-x;}
int num=0;
while (x){ out[num++]=(x%10); x=x/10;}
FORM(i,num-1,0) putchar(out[i]+'0'); putchar(ch);
}
/*==================split line==================*/
const double eps=1e-8;
map<char, int> c;
char s[maxn];
int main(){
char t[] = "Bulbsar";
scanf("%s",s);
int n = strlen(s);
FORP(i, 0, n - 1) c[s[i]] ++;
c['a']/=2; c['u'] /=2;
int m = 6, ans = INF;
FORP(i, 0, m) ans = min(ans, c[t[i]]);
write(ans,'\n');
}