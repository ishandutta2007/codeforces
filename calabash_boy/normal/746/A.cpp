#include <cstdio>  
#include <cmath>  
#include <ctime>  
#include <string>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
  
#include <set> 
#include <stack>  
#include <queue>  
#include <vector>  
#include<map>
#include<list>
 
#define pb push_back 
#define lb lower_bound 
#define sqr(x) (x)*(x) 
#define lowbit(x) (x)&(-x)  
#define Abs(x) ((x) > 0 ? (x) : (-(x)))  
#define forup(i,a,b) for(int i=(a);i<=(b);i++)  
#define fordown(i,a,b) for(int i=(a);i>=(b);i--)  
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
 fordown(i,num-1,0) putchar(out[i]+'0'); putchar(ch); 
} 
/*========================================================*/
int main()
{int i;
	int a,b,c;
	int ans=0;
	cin>>a>>b>>c;
	for( i=0;i*4<=c;i++)
	{ if(i*2>b||i*1>a) break;
	}
	cout<<(i-1)*7;
    return 0;
}