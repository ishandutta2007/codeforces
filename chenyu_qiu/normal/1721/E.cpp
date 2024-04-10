#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+30;
const int ha=131;
char t[N];
char s[N];
int ne[N];
int n,m;
int tr[N][26];
int ne2[N];
int ne3[N];
int cnt;
void insert(){
	int p=0;
	for(int i=1;i<=m;i++){
		if(!tr[p][t[i]-'a'])tr[p][t[i]-'a']=++cnt;
		p=tr[p][t[i]-'a'];
		ne3[p]=ne2[i];
	}
}
void getnext(){
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i])j=ne[j];
		if(s[j+1]==s[i])j++;
		ne[i]=j;
	}
}
void getnext2(){
	for(int i=n+1,j=ne[n],p=0;i<=n+m;i++){
		if(p!=-1&&tr[p][s[i]-'a']){
			p=tr[p][s[i]-'a'];
			ne[i]=ne3[p];
			j=ne[i];
			printf("%d ",ne[i]);
		}
		else {
			p=-1;
			while(j&&s[j+1]!=s[i])j=ne[j];
			if(s[j+1]==s[i])j++;
			ne[i]=j;
			printf("%d ",ne[i]);	
		}	
		ne2[i-n]=ne[i];
	}
	printf("\n");
	insert();
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	getnext();
	int T;
	cin>>T;
	while(T--){
		scanf("%s",t+1);
		m=strlen(t+1);
		for(int i=1;i<=m;i++)s[n+i]=t[i];
		getnext2();
	}
}