#include<bits/stdc++.h>
using namespace std;
long long p[100],tot=0,s[100];
int main(){
	long long n,i,s1=0;
	cin>>n;
	for(i=2;i*i<=n;++i){
		if(n%i==0){
			p[++tot]=i;
			while(n%i==0){
				n/=i;
				++s[tot];
			}
		}
	}
	if(n>1){
		p[++tot]=n;
		s[tot]=1;
	}
	for(i=1;i<=tot;++i)s1+=s[i];
	if(s1<=1)puts("1\n0");
	else if(s1==2)puts("2");
	else if(tot>=2){
		printf("1\n%lld\n",p[1]*p[2]);
	}
	else printf("1\n%lld\n",p[1]*p[1]);
	return 0;
}