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
int t,a,b,x,y;
void solve(){
	if(a>b)swap(a,b);
	if(x>y)swap(x,y);
	//a<=b x<=y
	if(x<a||y<b)return puts("0"),void();
	if(a==b)return write(x/a),putchar('\n'),void();
	int cur=min((y-x)/(b-a),min(x/a,y/b));
	int ans=cur+min(x-cur*a,y-cur*b)/(a+b)*2;
	if(x-cur*a>=a&&y-cur*b>=b)cur++;
	chkmx(ans,cur+min(x-cur*a,y-cur*b)/(a+b)*2);
	write(ans);putchar('\n');
}
signed main(){
	read(t);
	for(int i=1;i<=t;i++){
		read(x,y,a,b);
		solve();
	}
}