//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1004,mod=1e9+7;
int f[N][2][N],a[N],T,k;
int solve(int p,bool s,int pre,bool fl){
	if(!p)return s;
	if(!fl&&f[p][s][pre]!=-1)return f[p][s][pre];
	int ret=0,mx=fl?a[p]:9;
	for(int i=0;i<=mx;i++)
		ret=(ret+solve(p-1,s|((i==4||i==7)&&pre&&(pre-p<=k)),(i==4||i==7)?p:pre,fl&&(i==mx)))%mod;//
	if(!fl)f[p][s][pre]=ret;
	return ret;
}
char su[N],sv[N];
signed main(){
	memset(f,-1,sizeof(f));
	T=read();k=read();
	int lu,lv,tmp;
	while(T--){
		scanf("%s%s",su+1,sv+1);
		lu=strlen(su+1);lv=strlen(sv+1);
		memset(a,0,sizeof(a));
		for(int i=1;i<=lu;i++)a[i]=su[lu-i+1]^48;
		a[tmp=1]--;
		while(a[tmp]<0){
			a[tmp]+=10;
			a[++tmp]--;
		}
		tmp=solve(lu,0,0,1);
		for(int i=1;i<=lv;i++)a[i]=sv[lv-i+1]^48;
		cout<<(solve(lv,0,0,1)-tmp+mod)%mod<<"\n";
	}
	return (0-0);
}