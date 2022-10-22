// Problem: B. Scenes From a Memory
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/B
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
const int N=700;
int t,k;char c[N];
bool isp[N];
signed main(){
	for(int i=2;i<=100;i++){
		isp[i]=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0)isp[i]=0;
		//if(isp[i])printf("%d\n",i);;
	}
	read(t);while(t--){
		read(k);scanf("%s",c+1);
		for(int i=1;i<=k;i++)
			if(!isp[c[i]-'0']){
				write(1);putchar('\n');
				write(c[i]-'0');putchar('\n');
				goto loop;
			}
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++){
				int x=c[i]-'0';
				int y=c[j]-'0';
				if(!isp[x*10+y]){
					write(2);putchar('\n');
					write(x*10+y);putchar('\n');
					goto loop;
				}
			}
		loop:;
	}
}