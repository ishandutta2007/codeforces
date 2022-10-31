#include<bits/stdc++.h>
const int N=1005;
using namespace std;

char s[N],q[N],a[N];
int n,t,nx[N],m,S;

bool kmp(){
	for(int i=1,j=0;i<=n;i++){
		while(j&&q[j+1]!=a[i])j=nx[j];
		if(q[j+1]==a[i])j++;
		if(j==m)return 1;
	}return 0;
}

bool chk(){
	for(int i=1;i<=S;i++){
		for(int j=1;j<=i;j++)a[j]=s[j];
		for(int j=i-1;j;j--)a[i+i-j]=s[j];
		n=i*2-1;
		if(kmp())return 1;
	}return 0; 
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",s+1,q+1),S=strlen(s+1),m=strlen(q+1);
		memset(nx,-1,sizeof(nx));
		for(int i=2,j=0;i<=m;i++){
			while(j&&q[j+1]!=q[i])j=nx[j];
			if(q[j+1]==q[i])j++;
			nx[i]=j;
		}
		printf("%s\n",chk()?"YES":"NO");
	}
}