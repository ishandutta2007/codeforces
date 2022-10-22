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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e4+100;
int n,k,a[N],lst[N],nxt[N];
pair<int,int>ans[N];
signed main(){
	//n k
	read(n,k);
	for(int i=1;i<=n*k;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)lst[i]=n*k+1;
	for(int i=n*k;i;i--){
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int l=1;l<=n;l+=k-1){
		int r=min(n,l+k-2);
		for(int i=1;i<=n*k;i++){
			if(a[i]<l||a[i]>r)continue;
			if(lst[a[i]]<i&&lst[a[i]]!=-1){
				ans[a[i]]=mp(lst[a[i]],i);
				lst[a[i]]=-1;
				for(int j=l;j<=r;j++)if(lst[j]!=-1)
					while(lst[j]<i)
						lst[j]=nxt[lst[j]];
			}
		}
	}
	for(int i=1;i<=n;i++)
		write(ans[i].fi),putchar(' '),write(ans[i].se),putchar('\n');
}