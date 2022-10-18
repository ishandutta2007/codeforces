#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxm=13;
const long long hm=314159;

const long long h1=357657173359;
const long long h2=1926081719260817;

int n,m;
int x[maxm][maxn];
long long ha[maxm][maxn];
long long hb[maxm][maxn];
long long pwa[maxn];
long long pwb[maxn];
int idx[maxm][maxn];
int s[maxm];
long long ans[maxn];
int seq[maxn],sl=0;

bool eq(int x,int xl,int xr,int y,int yl,int yr){
	return ((((ha[x][xr]-ha[x][xl-1]*pwa[xr-xl+1])%h1+h1)%h1)==(((ha[y][yr]-ha[y][yl-1]*pwa[yr-yl+1])%h1+h1)%h1))&&((((hb[x][xr]-hb[x][xl-1]*pwb[xr-xl+1])%h2+h2)%h2)==(((hb[y][yr]-hb[y][yl-1]*pwb[yr-yl+1])%h2+h2)%h2));
}

bool chk(int l){
	for(int i=1;i<m;i++){
		if(!eq(i,s[i],s[i]+l-1,i+1,s[i+1],s[i+1]+l-1)) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
			idx[i][x[i][j]]=j;
		}
	}
	for(int i=1;i<=n;i++){
		int cud=x[1][i];
		int mx=0;
		if(ans[cud]!=0) continue;
		for(int j=1;j<=m;j++){
			s[j]=idx[j][cud];
			mx=max(mx,s[j]);
		}/*
		int l=1,r=n-mx+1;
		while(r-l>3){
			int m=(l+r)/2;
			if(chk(m)) l=m;
			else r=m;
		}
		for(int i=r;i>=l;i--){
			if(chk(i)){
				ans+=i;
				break;
			}
		}*/
		sl=0;
		int fs=0;
		for(int j=1;j<=n-mx+1;j++){
			bool ok=1;
			for(int k=1;k<m;k++){
				if(x[k][s[k]+j-1]!=x[k+1][s[k+1]+j-1]){
					ok=0;
					break;
				}
			}
			if(!ok) break;
			if(ans[x[1][s[1]+j-1]]!=0){
				fs=ans[x[1][s[1]+j-1]];
				break;
			}
			seq[sl++]=x[1][s[1]+j-1];
		}
		for(int j=0;j<sl;j++) ans[seq[j]]=sl-j+fs;
	}
	long long fans=0;
	for(int i=1;i<=n;i++) fans+=ans[i];
	cout<<fans;
	return 0;
}