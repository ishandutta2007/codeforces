#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
char s[100002];
int T,M;
int main(){
	int Q,n,z,i;
	scanf("%d",&Q);
	while(Q--){
		T=M=0;
		bool flg=1;
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;++i)M+=(s[i]=='M');
		if(M*3!=n){
			puts("NO");
			continue;
		}
		T=M=0;
		for(i=1;i<=n;++i){
			if(s[i]=='T')++T;
			else ++M;
			if(M>T){
				flg=0;
				break;
			}
		}
		T=M=0;
		for(i=n;i>=1;--i){
			if(s[i]=='T')++T;
			else ++M;
			if(M>T){
				flg=0;
				break;
			}
		}
		if(flg)puts("YES");
		else puts("NO");
	}
	return 0;
}