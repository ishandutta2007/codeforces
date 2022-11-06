#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[102];
bool bo[20002];
int main(){
	int T,n,i,s=0,j;
	bo[1]=1;
	for(i=2;i<=20000;++i){
		if(!bo[i]){
			for(j=i+i;j<=20000;j+=i)bo[j]=1;
		}
	}
	read(T);
	while(T--){
		read(n);
		s=0;
		for(i=1;i<=n;++i){
			read(a[i]);
			s+=a[i];
		}
		if(n==3&&a[1]==a[2]&&a[2]==a[3]&&s==3){
			puts("1");puts("1");
			continue;
		}
		if(bo[s]){
			printf("%d\n",n);
			for(i=1;i<=n;++i)printf("%d ",i);
			puts("");
			continue;
		}
		for(i=1;i<=n;++i){
			if(bo[s-a[i]])break;
		}
		printf("%d\n",n-1);
		for(j=1;j<=n;++j){
			if(j!=i)printf("%d ",j);
		}
		puts("");
	} 
	return 0;
}