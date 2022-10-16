#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
bitset<2005> f[65536];
int n,m,a[16];
vector<int> c[105];
void dfs(int s,int val,int d){
	if (s==(1<<n)-1)return;
	if (val!=0&&val%m==0&&f[s][val/m]==1){
		dfs(s,val/m,d+1);
		return;
	}
	for (int i=0;i<n;i++){
		if ((!(s&(1<<i)))&&f[s|(1<<i)][val+a[i]]==1){
			c[d].push_back(a[i]);
			dfs(s|(1<<i),val+a[i],d);
			return;
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>a[i];
	f[(1<<n)-1][1]=1;
	for (int i=(1<<n)-1;i>=0;i--){
		for (int j=0;j<n;j++)
			if (!(i&(1<<j)))f[i]|=(f[i|(1<<j)]>>a[j]);
		for (int j=1;j<=2000;j++){
			if (i==(1<<n)-1&&j==1)continue;
			if (j!=0&&j%m==0&&f[i][j/m]==1)f[i][j]=1;
		}
	}
	if (f[0][0]==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs(0,0,0); 
	for (int i=0;i<100;i++){
		int t=0;
		for (int j=0;j<(int)c[i].size();j++){
			if (t!=0)cout<<t<<' '<<c[i][j]<<endl;
			t+=c[i][j];
			if (t%m==0){
				int j=i;
				while(t%m==0)t/=m,j++;
				c[j].push_back(t);
				t=0;
			}
		}
	}
	return 0;
}
//mod zjf