#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m;
char s[1000005];
int f[1000005],mx[1000005],ans1,ans2;
int id(int x,int y){
	if (x<1||x>n||y<1||y>m)return 0;
	return (x-1)*m+y;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%s",s+1+(i-1)*m);
		ans1=0;
		for (int i=0;i<=n*m;i++)f[i]=mx[i]=0;
		for (int j=1;j<=m;j++)
			for (int i=1;i<=n;i++){
				mx[id(i,j)]=max(mx[id(i-1,j-1)],mx[id(i+1,j-1)]);
				mx[id(i,j)]=max(mx[id(i,j)],mx[id(i,j-1)]);
				if ((i+j)&1)continue;
				f[id(i,j)]=mx[id(i,j-1)];
				if (s[id(i,j)]=='1')f[id(i,j)]++;
				mx[id(i,j)]=max(mx[id(i,j)],f[id(i,j)]);
				ans1=max(ans1,f[id(i,j)]);
			}
		ans2=0;
		for (int i=0;i<=n*m;i++)f[i]=mx[i]=0;
		for (int j=1;j<=m;j++)
			for (int i=1;i<=n;i++){
				mx[id(i,j)]=max(mx[id(i-1,j-1)],mx[id(i+1,j-1)]);
				mx[id(i,j)]=max(mx[id(i,j)],mx[id(i,j-1)]);
				if (!((i+j)&1))continue;
				f[id(i,j)]=mx[id(i,j-1)];
				if (s[id(i,j)]=='1')f[id(i,j)]++;
				mx[id(i,j)]=max(mx[id(i,j)],f[id(i,j)]);
				ans2=max(ans2,f[id(i,j)]);
			}
		cout<<ans1+ans2<<endl;
	}
	return 0;
}