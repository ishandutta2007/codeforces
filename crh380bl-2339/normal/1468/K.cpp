#include<bits/stdc++.h>
#define ll long long
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
int nx,ny;
char s[5005];
int A[5005],B[5005],n;
bool chk(int x,int y){
	if(x==0&&y==0)return 0;
	int nx=0,ny=0,ax,ay;
	int i;
	for(i=1;i<=n;++i){
		ax=nx;ay=ny;
		if(s[i]=='L')--ax;
		else if(s[i]=='R')++ax;
		else if(s[i]=='U')++ay;
		else --ay;
		if(ax!=x||ay!=y){
			nx=ax;
			ny=ay;
		}
	}
	return nx==0&&ny==0;
}
int main(){
	int T,i;
	read(T);
	bool flg=0;
	while(T--){
		nx=ny=0;flg=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<=n;++i){
			if(s[i]=='L')--nx;
			else if(s[i]=='R')++nx;
			else if(s[i]=='U')++ny;
			else --ny;
			A[i]=nx;
			B[i]=ny;
		}
		for(i=1;i<=n;++i){
			if(chk(A[i],B[i])){
				printf("%d %d\n",A[i],B[i]);
				flg=1;
				break;
			}
		}
		if(!flg)puts("0 0");
	}
	return 0;
}