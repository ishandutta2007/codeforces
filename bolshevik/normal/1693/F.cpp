#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,mx[o];char s[o];bool flg;
inline int slv(){
	scanf("%d%s",&n,s+1);
	for(int i=flg=1;i<n;++i) flg&=(s[i]<=s[i+1]);
	if(flg) return 0;
	int res=1,c0=0,c1=0,nw=1;
	for(int i=1;i<=n;++i) if(s[i]=='0') ++c0;else ++c1;
	if(c0<c1){
		swap(c0,c1);
		for(int i=1,j=n;i<j;swap(s[i++],s[j--]));
		for(int i=1;i<=n;++i) s[i]=97-s[i];
	}
	for(int i=1,sm=0;i<=n;++i) if((sm+=(s[i]>48?-1:1))>=0) mx[sm]=i;
	for(;nw<=n&&s[nw]=='0';++nw);
	for(;nw<=c0-c1;nw+=(mx[nw-1]-nw+1)/2) ++res;
	return res;
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",slv()));
	return 0;
}