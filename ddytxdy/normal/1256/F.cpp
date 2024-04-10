#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
const int N=2e5+50;
int t,n,s[26],s2[26],f1,f2,flag;char a[N],b[N];
void add(int x){s[x]++;}
int ask(int x){int y=0;for(int i=x+1;i<26;i++)y+=s[i];return y;}
void main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s%s",&n,a+1,b+1);f1=0,f2=0;flag=0;
		memset(s,0,sizeof(s));
		for(int i=1,d;i<=n;i++){
			f1^=ask(d=a[i]-'a')&1;
			if(s[d])flag=1;add(d);
		}
		memcpy(s2,s,sizeof(s));
		memset(s,0,sizeof(s));
		for(int i=1,d;i<=n;i++){
			f2^=ask(d=b[i]-'a')&1;
			if(s[d])flag=1;add(d);
		}
		for(int i=0;i<26;i++)if(s[i]!=s2[i])flag=0,f1=0,f2=1;
		puts(flag||!(f1^f2)?"Yes":"No");
	}
}
}
int main(){ZBK::main();return 0;}