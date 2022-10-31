#include<cstdio>
#include<iostream>
#include<algorithm>
#include<bitset>
#define N 303
using namespace std;
int n,m;
int ma[N][N];
bitset<N> a[N],c[N],b[N],h0,h1;
int flag=-1;
void check(){
	//printf("1111\n");
	if(flag==1)return;
	bitset<N>ans1,ans2,now;
	for(int i=1;i<=n;i++)c[i]=a[i]^b[i];
	ans2=h0^c[1];
	for(int i=2;i<=n;i++){
		now=h0^c[i];
		//for(int j=1;j<=m;j++)cout<<'='<<b[i][j]<<' ';printf("\n");
		if(now==ans2){
			continue;
		}
		now=h1^c[i];
		//printf("2222\n");
		if(now==ans2){
			ans1.set(i);
			continue;
		}
		return;
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<ans1[i];cout<<"\n";
	for(int i=1;i<=m;i++)cout<<ans2[i];
	exit(0);
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&ma[i][j]);
			if(ma[i][j]==1)a[i].set(j);
		}
	}
	for(int i=1;i<=m;i++){
		h1.set(i);
	}
	check();
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			b[i].set(j);
			check();
		}
	}
	if(flag==-1){puts("NO");}
	return 0;
}