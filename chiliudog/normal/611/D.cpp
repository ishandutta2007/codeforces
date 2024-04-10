#include<bits/stdc++.h>
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
typedef long long int64;
const int maxn=5005,mod=1000000007;
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int sum[maxn][maxn],lcp[maxn][maxn],f[maxn][maxn],n;
char a[maxn];
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main(){
	read(n);scanf("%s",a+1);
	per(i,n,1)rep(j,i,n)
		if(a[i]==a[j])lcp[i][j]=min(lcp[i+1][j+1]+1,j-i);
	rep(i,0,n)sum[i][0]=1;
	rep(j,1,n){
		rep(i,1,j){
			if(a[i]=='0')continue;
			f[i][j]=sum[j-i][i-1];
			int len=j-i+1;
			if((i-1)>=len){
				int k=(i-1)-len+1;
				if(lcp[k][i]!=len&&a[k+lcp[k][i]]<a[i+lcp[k][i]]){
					f[i][j]+=f[k][i-1];
				}
				if(f[i][j]>=mod)f[i][j]-=mod;
			}
			sum[j-i+1][j]+=f[i][j];if(sum[j-i+1][j]>=mod)sum[j-i+1][j]-=mod; 
		}
		rep(i,1,n)sum[i][j]=(sum[i-1][j]+sum[i][j])%mod;
	}
	int ans=0;
	rep(i,1,n){
		ans+=f[i][n];if(ans>=mod)ans-=mod; 
	}cout<<ans<<endl;
//	cout<<f[5][8];
	return 0;
}