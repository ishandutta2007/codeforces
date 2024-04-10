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
const int N=2e5+100;
int t,n,a[N];
vector<int>ans;
void chk(int x){
	ans.pb(x);
	int _=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=_;
}
void work(int l,int r){
	if(l==r)return;
	assert((r-l)%2==0);
	for(int i=l;i+2<=r;i+=2)
		chk(i);
	for(int i=r-4;i>=l;i-=2)
		chk(i);
}
void out(){
	puts("Yes");
	write(ans.size());putchar('\n');
	for(auto x:ans)write(x),putchar(' ');
	putchar('\n');ans.clear();
}
signed main(){
	read(t);
	for(int orzemptyhope=1;orzemptyhope<=t;orzemptyhope++){
		read(n);
		int sum=0;for(int i=1;i<=n;i++)read(a[i]),sum^=a[i];
		if(sum==1)puts("No");
		else{
			if(n&1)work(1,n),out();
			else{
				int sum=0;int id=-1;
				for(int i=1;i<=n;i++){
					sum^=a[i];
					if(i%2==1&&sum==0)
						id=i;
				}
				if(id==-1)puts("No");
				else{
					work(1,id);work(id+1,n);
					out();
				}
			}
		}
	}
}