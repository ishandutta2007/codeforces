/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int lowbit(int x){return x&-x;} 
const int N=500000,M=1000000;
int n,m;
char a[N+5],b[N+5],c[M+5];
int lcP[N+1],Lcs[N+1];
int s;
char d[N+M+5];
void con(char x[],char y[]){
	s=0;
	for(int i=1;i<=m;i++)d[++s]=x[i];
	d[++s]='!';
	for(int i=1;i<=n;i++)d[++s]=y[i];
}
int z[N+M+1];
void z_init(){
	z[1]=s;
	int zl=0,zr=0;
	for(int i=2;i<=s;i++)
		if(zr<i){
			z[i]=0;
			while(i+z[i]<=s&&d[i+z[i]]==d[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=s&&d[i+z[i]]==d[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
struct bitree{
	int sum[M+1],cnt[M+1];
	void init(){
		memset(sum,0,sizeof(sum));
		memset(cnt,0,sizeof(cnt));
	}
	void add(int v){
		int x=v;
	    while(x<=n)sum[x]+=v,cnt[x]++,x+=lowbit(x);
	}
	void del(int v){
		int x=v;
		while(x<=n)sum[x]-=v,cnt[x]--,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
	int Cnt(int x){
		int res=0;
		while(x)res+=cnt[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	scanf("%lld%lld%s%s%s",&n,&m,a+1,b+1,c+1);
	con(c,a);
	z_init();
	for(int i=1;i<=n;i++)lcP[i]=z[m+1+i];
	reverse(b+1,b+n+1);reverse(c+1,c+m+1);con(c,b);
	z_init();
	for(int i=1;i<=n;i++)Lcs[i]=z[m+1+(n-i+1)];
//	for(int i=1;i<=n;i++)printf("%lld %lld\n",lcP[i],Lcs[i]);
	int ans=0;
	bit.init();
	for(int i=1;i<=min(n,m-1);i++)bit.add(max(1ll,m-Lcs[i]));
	for(int i=1;i<=n;i++){
		if(i>1)bit.del(max(1ll,m-Lcs[i-1])),i+m-2<=n&&(bit.add(max(1ll,m-Lcs[i+m-2])),0);
		ans+=(min(m-1,lcP[i])+1)*bit.Cnt(min(m-1,lcP[i]))-bit.Sum(min(m-1,lcP[i]));
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
/*1
6 5
aabbaa
baaaab
aaaaa
*/
/*2
5 4
azaza
zazaz
azaz
*/
/*3
9 12
abcabcabc
xyzxyzxyz
abcabcayzxyz
*/
/*4
1 2
t
t
tt
*/