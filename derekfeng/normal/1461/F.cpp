#include<bits/stdc++.h>
using namespace std;
const int M=2e5+1;
int n,a[100004],msk;
char buf[3];
char ans[100004];
vector<tuple<int,int,int> >v;
int dp[22][22],f[22],b[22],m;
void dfs(int x){
	if(x==0)return;
	int w=f[x],p;
	for(int i=1;i<=x;i++)if(dp[i][x]==w)p=i;
	for(int i=get<0>(v[p])+1;i<=get<1>(v[x]);i++)ans[i]='*';
	for(int i=get<0>(v[p]);i>=get<0>(v[p])-b[p];i--)ans[i]='+';
	dfs(p-1);
}
void solve(int l,int r){
	ans[l]='+';
	int now=1;
	for(int i=l;i<=r;i++){
		now*=a[i];
		if(now>=M){
			for(int j=l+1;j<=r;j++)ans[j]='*';
			return;
		}
	}
	v.clear();
	v.push_back(make_tuple(0,0,0)); 
	for(int i=l;i<=r;){
		if(a[i]==1){
			i++;
			continue;
		}
		int j=i,cur=1;
		for(;j<=r&&a[j]!=1;j++)cur*=a[j];
		v.push_back(make_tuple(i,j-1,cur));
		i=j;
	}
	memset(dp,0,sizeof(dp)),memset(f,0,sizeof(f));
	m=(int)v.size()-1;
	b[1]=0;
	for(int i=2;i<=m;i++)b[i]=get<0>(v[i])-1-get<1>(v[i-1]);
	for(int i=1;i<=m;i++){
		int cur=1;
		for(int j=i;j>=1;j--){
			cur*=get<2>(v[j]);
			dp[j][i]=f[j-1]+b[j]+cur;
			f[i]=max(f[i],dp[j][i]);
		}
	}
	dfs(m);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",buf);
	for(int i=0;i<strlen(buf);i++){
		if(buf[i]=='+')msk|=1;
		if(buf[i]=='-')msk|=2;
		if(buf[i]=='*')msk|=4;
	}
	if(msk==1||msk==3){putchar(a[1]+'0');for(int i=2;i<=n;i++)putchar('+'),putchar(a[i]+'0');return 0;}
	if(msk==2){putchar(a[1]+'0');for(int i=2;i<=n;i++)putchar('-'),putchar(a[i]+'0');return 0;}
	if(msk==4){putchar(a[1]+'0');for(int i=2;i<=n;i++)putchar('*'),putchar(a[i]+'0');return 0;}
	if(msk==6){
		int fi=0;
		for(int i=2;i<=n;i++)if(a[i]==0){
			fi=i;break;
		}
		putchar(a[1]+'0');
		if(!fi)for(int i=1;i<n;i++)putchar('*'),putchar(a[i+1]+'0');
		else{
			for(int i=1;i<fi-1;i++)putchar('*'),putchar(a[i+1]+'0');
			putchar('-');putchar('0');
			for(int i=fi;i<n;i++)putchar('*'),putchar(a[i+1]+'0');
		}
		return 0;
	}
	for(int i=1;i<=n;){
		if(a[i]==0){
			ans[i]='+';
			i++;continue;
		}
		int l=i,r=l;
		for(;r<=n&&a[r];r++);
		while(l<r&&a[l]==1)ans[l]='+',l++;
		if(l==r){i=l;continue;}
		int L=l,R=r-1;
		while(a[R]==1)ans[R]='+',R--;
		solve(L,R);
		i=r;
	}
	putchar(a[1]+'0'); 
	for(int i=2;i<=n;i++)putchar(ans[i]),putchar(a[i]+'0');
}