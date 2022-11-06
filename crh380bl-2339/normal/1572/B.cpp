#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],s[200005],stp,ans[1000002],n;
int chk(int x){
	return a[x]^a[x+1]^a[x+2];
}
void opt(int x){
	if(a[x]==a[x+1]&&a[x]==a[x+2])return;
	ans[++stp]=x;
	int t=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=t;
}
void go_left(int x){
	int i;
	for(i=x;i>=3;){
		if(i>3){
			opt(i-3);
			opt(i-2);
			i-=2;
		}
		else{
			opt(1);
			break;
		}
	}
}
void go_right(int x){
	int i;
	for(i=x;i<=n-2;){
		if(i<n-2){
			opt(i+1);
			opt(i);
			i+=2;
		}
		else{
			opt(i);
			break;
		}
	}
}
void print(){
	puts("YES");
	int i;printf("%d\n",stp);
	for(i=1;i<=stp;++i){
		if(i<stp)printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
}
int main(){
	int T,i,j,k;
	bool flg;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		if(s[n]&1){
			puts("NO");
			continue;
		}
		flg=0;stp=0;
		for(i=1;i<=n;++i){
			if(!a[i]&&(!(s[i]&1))){
				go_left(i);
				go_right(i);
				flg=1;
				break;
			}
		}
		if(flg){
			print();
			continue;
		}
		for(i=1;i<=n&&!flg;){
			if(a[i])++i;
			else{
				for(j=i;a[j]==0;++j);
				if((j-i)&1){
					flg=1;
					for(k=i;k<j;k+=2)opt(k-1);
					go_left(j-1);
					go_right(j-1);
					break;
				}
				i=j;
			}
		}
		if(!flg)puts("NO");
		else print();
		//for(i=1;i<=n;++i)assert(a[i]==0);
	}
	return 0;
}