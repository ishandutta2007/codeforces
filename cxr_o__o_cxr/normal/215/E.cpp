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
int f[80][80][40][2],b[80],a[80],ans[80][80];
int dp(int p,int k,int c,bool s,bool _0,bool fl){
	if(k<=c)return 0;
	if(!p){
		if(s)ans[k][c]++;
		return s; 
	}
	if(!_0&&k%c)return 0;
	if(!fl&&!_0&&f[p][k][c][s]!=-1){
		ans[k][c]+=f[p][k][c][s];
		return f[p][k][c][s];
	}
	int ret=0,mx=fl?a[p]:1;
	for(int i=0;i<=mx;i++){
		b[p]=i;
		ret+=dp(p-1,k-(_0&&(i==0)),c,s&((_0||k-p<c)?1:b[p]==b[p+c]),_0&&(i==0),fl&&(i==mx));
	}
	if(!fl&&!_0)f[p][k][c][s]=ret;
	return ret;
}
inline int solve(int x){
	int m=0,ret=0;
	while(x){
		a[++m]=x&1;
		x>>=1;
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=(m>>1);i++)
		dp(m,m,i,1,1,1);
	for(int i=1;i<=m;i++){
		for(int c=1;c<i;c++){
			if(i%c)continue;
//			cerr<<ans[i][c]<<" ";
			for(int k=1;k<c;k++)
				if((c%k)==0)ans[i][c]-=ans[i][k];
			ret+=ans[i][c];
		}
//		puts("");
	}
	return ret;
}
signed main(){
	memset(f,-1,sizeof(f));
	int u=read(),v=read();
	cout<<solve(v)-solve(u-1);
	return (0-0);
}