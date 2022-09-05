#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 1000000;
int n,v[N];
int x,y=(1023),z;
char ch[N],str[N];
inline int getans(int BIT, int val) { //i-th bit
	int now=val; 
	rep(i,1,n) {
		if (ch[i]=='|') now=now|(v[i]>>BIT);
		if (ch[i]=='&') now=now&(v[i]>>BIT);
		if (ch[i]=='^') now=now^(v[i]>>BIT);
	}
	return now&1;
}
int main() {
	read(n); rep(i,1,n) {scanf("%s",str); ch[i]=str[0]; read(v[i]);}
	rep(i,0,9) {
		int v0=getans(i,0),v1=getans(i,1);
		if (v0==1 && v1==0) x|=(1<<i);
		else if (v0==0 && v1==0) y^=(1<<i);
		else if (v0==1 && v1==1) z|=(1<<i);
	}
	puts("3");
	printf("^ %d\n",x);
	printf("& %d\n",y);
	printf("| %d\n",z);
	return 0;
}