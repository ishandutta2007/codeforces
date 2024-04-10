// Problem: C. Grandma Capa Knits a Scarf
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100;
int t,n;char c[N];
int get(char del){
	int l=1,r=n;int cnt=0;
	while(l<=r){
		if(c[l]==c[r])l++,r--;
		else if(c[l]==del)l++,cnt++;
		else if(c[r]==del)r--,cnt++;
		else return 0x3f3f3f3f;
	}
	return cnt;
}
signed main(){
	read(t);
	while(t--){
		read(n);
		scanf("%s",c+1);
		int l=1,r=n;while(l<=r&&c[l]==c[r])l++,r--;
		if(l>r)puts("0");
		else{
			int ans=min(get(c[l]),get(c[r]));
			if(ans==0x3f3f3f3f)puts("-1");
			else write(ans),pc('\n');
		}
	}
}