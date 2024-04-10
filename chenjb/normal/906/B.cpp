#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
int a[N],ans[N],tp[N],n,m;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m)a[(i-1)*m+j]=(i-1)*m+j;
	if(n>4){
		puts("YES");
		rep(i,n)tp[i]=(i&1)?(i+1)/2:(n+1)/2+i/2;
		rep(j,m)rep(i,n)ans[(i-1)*m+j]=a[(tp[(i+j-1)%n+1]-1)*m+j];
		rep(i,n)rep(j,m)printf("%d%c",ans[(i-1)*m+j],j==m?'\n':' ');
	}else if(m>4){
		puts("YES");
		rep(i,m)tp[i]=(i&1)?(i+1)/2:(m+1)/2+i/2;
		rep(i,n)rep(j,m)ans[(i-1)*m+j]=a[(i-1)*m+tp[(i+j-1)%m+1]];
		rep(i,n)rep(j,m)printf("%d%c",ans[(i-1)*m+j],j==m?'\n':' ');
	}else{
		if(n==1&&m==1){
			puts("YES");
			puts("1");
		}
		if((n==1&&m==2)||(n==2&&m==1)){puts("NO");}
		if((n==1&&m==3)||(n==3&&m==1)){puts("NO");}
		if((n==1&&m==4)){
			puts("YES");
			puts("2 4 1 3");
		}
		if((n==4&&m==1)){
			puts("YES");
			printf("2\n4\n1\n3\n");
		}
		if((n==2&&m==2)){puts("NO");}
		if((n==2&&m==3)||(n==3&&m==2)){puts("NO");}
		if(n==2&&m==4){
			puts("YES");
			printf("5 4 7 2\n3 6 1 8\n");
		}
		if(n==4&&m==2){
			puts("YES");
			printf("1 5\n4 8\n7 2\n3 6\n");
		}
		if(n==3&&m==3){
			puts("YES");
			printf("1 3 8\n5 9 4\n7 2 6\n");
		}
		if(n==3&&m==4){
			puts("YES");
			printf("1 3 5 2\n4 6 12 9\n11 8 10 7\n");
		}
		if(n==4&&m==3){
			puts("YES");
			printf("1 3 5\n6 8 10\n2 4 12\n9 11 7\n");
		}
		if(n==4&&m==4){
			puts("YES");
			printf("6 8 5 7\n14 16 13 15\n2 4 1 3\n10 12 9 11\n");
		}
	}
	return 0;
}