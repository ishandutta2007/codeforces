// Problem: F1. Nearest Beautiful Number (easy version)
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
int t;
char n[60];int len,k;bool flag=false;
void dfs(int now,int st,int cnt,bool d,int val){
	if(cnt>k)return;
	if(flag)return;
	if(now==len+1){
		printf("%d\n",val);flag=1;
		return;
	}
	int D=n[now]-'0';if(!d)D=0;
	for(int i=D;i<=9;i++){
		int ss=st,cc=cnt;
		if(now!=0){
			if(!(ss>>i&1))
				ss|=(1<<i),cc++;
		}
		dfs(now+1,ss,cc,d && i==D,val*10+i);
	}
}
signed main(){
	read(t);
	while(t--){
		n[0]='0';scanf("%s",n+1);scanf("%d",&k);
		len=strlen(n+1);
		flag=false;
		dfs(0,0,0,1,0);
	}
}