// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.ml/contest/1559/problem/B
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
const int N=1e5+100;
int t,n;char str[N];bool vis[N];
signed main(){
	read(t);;while(t--){
		read(n);scanf("%s",str+1);
		int pos=-1;
		for(int i=1;i<=n;i++)if(str[i]!='?'){
			pos=i;
			break;
		}
		if(pos==-1){
			for(int i=1;i<=n;i++)
				if(i&1)putchar('R');
				else putchar('B');
		}else{
			for(int i=pos-1;i;i--)
				if(str[i+1]=='R')str[i]='B';
				else str[i]='R';
			for(int i=pos+1;i<=n;i++){
				if(str[i]=='?'){
					if(str[i-1]=='R')str[i]='B';
					else str[i]='R';
				}
			}
			printf("%s",str+1);
		}
		putchar('\n');
	}
}