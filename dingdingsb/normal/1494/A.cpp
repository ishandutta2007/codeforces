// Problem: CF1494A ABC String
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1494A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
int t,n;
char s[100];
bool chk(int a,int b,int c){
	int res=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='A')res+=a;
		if(s[i]=='B')res+=b;
		if(s[i]=='C')res+=c;
		if(res<0)return false;
	}
	return res==0;
}
signed main(){
	read(t);
	while(t--){
		scanf("%s",s+1);n=strlen(s+1);
		if(chk(1,1,-1)||chk(1,-1,-1)||chk(1,-1,1)||chk(-1,1,1)||chk(-1,1,-1)||chk(-1,-1,1))
			puts("YES");
		else puts("NO");
	}
}