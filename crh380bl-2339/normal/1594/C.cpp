#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
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
char c[3];
char s[300005];
int chk1(){
	int i;
	for(i=1;s[i];++i)if(s[i]!=c[0])return i;
	return -1;
}
int main(){
	int T,n,m,l,i,j;
	bool flg;
	scanf("%d",&T);
	while(T--){
		read(n);
		scanf("%s%s",c,s+1);l=strlen(s+1);
		m=chk1();
		if(m==-1){
			puts("0");
			continue;
		}
		for(i=1;i<=l;++i){
			flg=1;
			for(j=i;j<=l;j+=i)if(c[0]!=s[j]){
				flg=0;
				break;
			}
			if(flg){
				printf("1\n%d\n",i);
				break;
			}
		}
		if(flg)continue;
		printf("2\n");
		for(i=1;l%i==0;++i);
		printf("%d %d\n",i,l);
	} 
	return 0;
}