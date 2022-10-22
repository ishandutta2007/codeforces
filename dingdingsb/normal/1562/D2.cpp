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
const int N=2e6+100;
int t,n,q,s[N];char str[N];
set<int>pos[N];
signed main(){
	read(t);while(t--){
		read(n,q);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++){
			int v=str[i]=='+'?1:-1;
			if(i&1)v=-v;s[i]=s[i-1]+v;
			pos[s[i]*2-v+2*n+1].insert(i);
		}
		while(q--){
			int l,r;read(l,r);
			if(s[r]-s[l-1]==0)puts("0");
			else{
				printf("%d\n",(r-l)%2+1);
				if((r-l+1)%2==0)printf("%d ",r),r--;
				printf("%d\n",*pos[s[l-1]+s[r]+2*n+1].lower_bound(l));
			}
		}
		for(int i=1;i<=n;i++){
			int v=str[i]=='+'?1:-1;
			if(i&1)v=-v;s[i]=s[i-1]+v;
			pos[s[i]*2-v+2*n+1].clear();
		}
	}
}