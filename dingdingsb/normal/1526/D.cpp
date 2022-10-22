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
const int maxn=1e5+100;
int t,n;char c[maxn];int a[maxn];
int cnt[4];
enum{A=0,N,T,O};
signed main(){
	read(t);
	while(t--){
		scanf("%s",c+1);n=strlen(c+1);
		for(int i=1;i<=n;i++)
			if(c[i]=='A')a[i]=A;
			else if(c[i]=='N')a[i]=N;
			else if(c[i]=='T')a[i]=T;
			else if(c[i]=='O')a[i]=O;
		vector<int>v={0,1,2,3};
		pair<ll,vector<int>>ans=mp(-1,vector<int>(4));
		do{
			ll res=0;
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++){
				cnt[a[i]]++;
				for(int j=3;v[j]!=a[i];j--)
					res+=cnt[v[j]];
			}
			chkmx(ans,mp(res,v));
		}while(next_permutation(v.begin(),v.end()));
		for(auto x:ans.se)
			for(int i=1;i<=n;i++)if(a[i]==x){
				if(x==A)putchar('A');
				if(x==N)putchar('N');
				if(x==T)putchar('T');
				if(x==O)putchar('O');
			}
		putchar('\n');
	}
}