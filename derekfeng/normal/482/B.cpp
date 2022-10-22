#include <bits/stdc++.h>
using namespace std;
int n,m,n_=1,ld[100004],rd[100004],xd[100004],dat[270004],res[100004];
int ans[100004][31];
void update(int l,int r,int id,int a,int b,int x){
	if (l>b || a>r) return;
	if (a<=l && r<=b){
		dat[id]|=x;
		return;
	}
	update(l,(l+r)/2,id*2+1,a,b,x);
	update((l+r)/2+1,r,id*2+2,a,b,x);
}
void init(int l,int r,int id,int now){
	now|=dat[id]; 
	if (l!=r){
		init(l,(l+r)/2,id*2+1,now);
		init((l+r)/2+1,r,id*2+2,now);
	}else res[l]=now;
}
int main(){
	cin>>n>>m;
	while(n_<n) n_<<=1;
	for (int i=1;i<=m;i++){
		scanf ("%d%d%d",&ld[i],&rd[i],&xd[i]);
		ld[i]--,rd[i]--;
		update(0,n_-1,0,ld[i],rd[i],xd[i]);
	}
	init(0,n_-1,0,0);
	for (int i=0;i<n;i++)
		for (int j=0;j<31;j++){
			if (i!=0) ans[i][j]=ans[i-1][j];
			if (res[i]&(1<<j))
				ans[i][j]++;
		}
	for (int i=1;i<=m;i++){
		int num=rd[i]-ld[i]+1; 
		for (int j=0;j<31;j++)if(((1<<j)&xd[i])==0){
			int a=ans[rd[i]][j];
			if (ld[i]!=0) a-=ans[ld[i]-1][j];
			if (a==num){
				puts("NO");return 0;
			}
		}
	}
	puts("YES");
	for (int i=0;i<n;i++) printf("%d ",res[i]);
}