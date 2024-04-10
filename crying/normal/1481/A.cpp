#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int t,x,y,len;
char s[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>s;
		len=strlen(s);
		int cx=0,cy=0,cntu=0,cntd=0,cntr=0,cntl=0;
		for(int i=0;i<len;i++){
			if(s[i]=='U')cy++,cntu++;
			else if(s[i]=='D')cy--,cntd++;
			if(s[i]=='R')cx++,cntr++;
			if(s[i]=='L')cx--,cntl++;
		}
		if(cx<x && cntl<(x-cx)){
			printf("NO\n");continue;
		}
		if(cx>x && cntr<(cx-x)){
			printf("NO\n");continue;
		}
		if(cy>y && cntu<(cy-y)){
			printf("NO\n");continue;
		}
		if(cy<y && cntd<(y-cy)){
			printf("NO\n");continue;
		}
		printf("YES\n");
	}
	return 0;
}