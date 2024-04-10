#include<cstdio>
#include<iostream>
using namespace std;
const int o=110;
int T,n,a[o],m,b[o],ma,mb;
int main(){
	for(scanf("%d",&T);T--;ma=mb=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),ma=max(ma,a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;++i) scanf("%d",&b[i]),mb=max(mb,b[i]);
		if(ma>mb) printf("Alice\nAlice\n");
		else if(ma<mb) printf("Bob\nBob\n");
		else printf("Alice\nBob\n");
	}
	return 0;
}