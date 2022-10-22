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
const int N=1e5+10;
int n;int tot,pr[N];bool npr[N];
void init(){
	for(int i=2;i<N;i++){
		if(!npr[i])
			pr[++tot]=i;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
}
int count(int x){
	int cnt=0;
	for(int i=1;i<=tot;i++){
		while(x%pr[i]==0)
			cnt++,x/=pr[i];
	}
	if(x>1)cnt++;
	return cnt;
}
int t,a,b,k;
signed main(){
	init();
	read(t);
	while(t--){
		read(a,b,k);
		int l,r;
		if(a==b)l=0;
		else if(a%b==0||b%a==0)l=1;
		else l=2;
		r=count(a)+count(b);
		if(k<l||r<k)puts("NO");
		else{
			if(k!=1)puts("YES");
			else puts(l==1?"YES":"NO");
		}
	}
}