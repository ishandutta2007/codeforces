#include<bits/stdc++.h>
#define int long long
const int N=35;
using namespace std;

int n,m;
string s[N];
int bel[N][N],ct;
int pr[N][N];
int col[N][N];

void solve(){
	
}

int r[N],a[N]={0,1,2,3,4,5,1,6,3,6,7,7,2,4,5};
int ans;
string res[N];
int cnt[N][N];
void check(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			col[i][j]=a[bel[i][j]];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;
			if(pr[i][j]==3)continue;
			if(pr[i][j]==1)cnt[col[i][j]][col[i+1][j]]++;
			if(pr[i][j]==2)cnt[col[i][j]][col[i][j+1]]++;
		}
	for(int i=1;i<=7;i++)
		for(int j=1;j<=7;j++){
			if(i==j&&cnt[i][j]!=1)return ;
			if(i!=j&&cnt[i][j]+cnt[j][i]!=1)return ;
		}
	if(!ans){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='.')res[i]+='.';
				else res[i]+=col[i][j]+'0'-1;
			}
		}
	}
	ans++;
}
void dfs(int k,int p){
//	cout<<k<<' '<<p<<endl;
	if(k==15)check();
	else{
		for(int i=1;i<p;i++)
			if(r[i])r[i]--,a[k]=i,dfs(k+1,p),r[i]++;
		if(p!=8)r[p]--,a[k]=p,dfs(k+1,p+1),r[p]++; 
	}
}

main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i],s[i]='0'+s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;
			if(bel[i][j])continue;
			++ct;
			bel[i][j]=bel[i+1][j]=bel[i+1][j+1]=bel[i][j+1]=ct;	
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;	
			if(pr[i][j])continue;
			if(s[i+1][j]==s[i][j])pr[i][j]=1,pr[i+1][j]=3;
			if(s[i][j+1]==s[i][j])pr[i][j]=2,pr[i][j+1]=3;
		} 
	for(int i=1;i<=7;i++)r[i]=2;
	dfs(1,1);
	cout<<ans*5040<<endl;
	for(int i=1;i<=n;i++)cout<<res[i]<<endl;
}