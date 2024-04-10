#include<bits/stdc++.h>
#define union union2
using namespace std;
const int maxn = 55;
char mp[maxn][maxn];
int m,n;
int fa[maxn+maxn];
int sz1[maxn+maxn];
int sz[maxn+maxn];
int cnt[maxn+maxn];
int find(int x){
	return fa[x]==x?x:fa[x] =find(fa[x]);
}
inline void union(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if (fx==fy)return;
	fa[fx] =fy;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		scanf("%s",mp[i]);
	}
	for (int i=0;i<m+n;i++){
		fa[i] =i;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (mp[i][j]=='#'){
				union(i,j+n);
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(mp[i][j]=='#'){
				cnt[find(i)]++;
			}
		}
	}
	for (int i=0;i<m+n;i++){
		sz[find(i)]++;
	}
	for (int i=0;i<n;i++){
		sz1[find(i)]++;
	}
	for (int i=0;i<m+n;i++){
		if (i==find(i)){
			sz[i] = sz1[i]*(sz[i]-sz1[i]);
			if (sz[i]!=cnt[i]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}