//nb 
//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
//using namespace std;
#define TP long long
#define int long long
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e5+10;
int sum[maxn][40];
int min[maxn][40];
int fa[maxn][40];
//[2]
// 
int n,k;
int num[40],pos;
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)
		fa[i][0]=read()+1;
	for(int i=1;i<=n;i++)
		sum[i][0]=min[i][0]=read();
	for(int i=1;i<=39;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1],
			sum[j][i]=sum[j][i-1]+sum[fa[j][i-1]][i-1],
			min[j][i]=std::min(min[j][i-1],min[fa[j][i-1]][i-1]);
	for(int i=0;i<=39;i++)
		if(k&(long long)std::pow(2,i))
			num[++pos]=i;
	for(int i=1;i<=n;i++){
		int p=i;
		int ans1=0,ans2=0x3f3f3f3f;
		for(int j=1;j<=pos;j++){
			ans1+=sum[p][num[j]];
			ans2=std::min(ans2,min[p][num[j]]);
			p=fa[p][num[j]];
		}
		write(ans1);putchar(' ');
		write(ans2);putchar('\n');
	}
	return 0;
}