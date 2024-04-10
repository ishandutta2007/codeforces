#include<bits/stdc++.h>
using namespace std;
const int M=110,N=1e4+100;
int a[M];
bool flag[M];
bool vis[M][N];
bool f[N];
signed main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(flag,0,sizeof flag);
		memset(f,0,sizeof f);
		memset(vis,0,sizeof vis);
		int n,x,sum=0;scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		if(sum<x){
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			puts("");
			goto loop;
		}
		sort(a+1,a+1+n);
		f[0]=1;
		for(int i=1;i<n;i++)
			for(int j=N-a[i]-1;j>=0;j--)
				if(f[j]){
					f[j+a[i]]=1;
					vis[i][j+a[i]]=true;
				} 
		for(int i=max(0,x+1-a[n]);i<x;i++)
			if(f[i]){
				puts("YES");
				for(int j=n-1;j;j--){
					if(vis[j][i]){
						printf("%d ",a[j]);
						flag[j]=true;
						i-=a[j];
					}
				}
				printf("%d ",a[n]);
				for(int j=1;j<n;j++)if(!flag[j])
					printf("%d ",a[j]);
				puts("");
				goto loop;
			}
		puts("NO");
		loop:;
	}
    return 0;
    cout<<"*fsb";
}