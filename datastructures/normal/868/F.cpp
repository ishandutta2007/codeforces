#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,k,a[100005],f[25][100005],book[100005],cnt;
void ins(int pos){
	cnt+=book[a[pos]];
	book[a[pos]]++;
	return;
}
void del(int pos){
	book[a[pos]]--;
	cnt-=book[a[pos]];
	return;
}
int dl=1,dr=0;
int val(int l,int r){
	while(dl<l)del(dl),dl++;
	while(dl>l)dl--,ins(dl);
	while(dr<r)dr++,ins(dr);
	while(dr>r)del(dr),dr--;
	return cnt;
}
void calc(int nowl,int nowr,int pl,int pr,int s){
	if (nowl>nowr)return;
	int mid=(nowl+nowr)/2;
	int p;
	for (int i=pl;i<=min(pr,mid);i++){
		if (val(i,mid)+f[s-1][i-1]<=f[s][mid])
			f[s][mid]=val(i,mid)+f[s-1][i-1],p=i;
	}
	calc(nowl,mid-1,pl,p,s);
	calc(mid+1,nowr,p,pr,s);
	return;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)a[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=k;i++)calc(1,n,1,n,i);
	cout<<f[k][n]<<endl;
	return 0;
}