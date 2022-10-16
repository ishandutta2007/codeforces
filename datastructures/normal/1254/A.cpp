#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,k,num;
char s[105][105];
char ans[105][105];
char ch(int x){
	if (x<=10)return '0'+x-1;
	x-=10;
	if (x<=26)return 'a'+x-1;
	x-=26;
	return 'A'+x-1;
}
void nxt(int &x,int &y){
	if (x&1){
		if (y==m){
			x++;
			return;
		}
		y++;
		return;
	}
	else{
		if (y==1){
			x++;
			return;
		}
		y--;
		return;
	}
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		num=0;
		for (int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for (int j=1;j<=m;j++)
				if (s[i][j]=='R')num++;
		}
		int c1,d1,c2,d2;
		c1=num/k,c2=num/k+1;
		d1=k-num%k,d2=num%k;
		int x=1,y=1;
		for (int i=1;i<=d1;i++){
			int qwq=0;
			while(qwq<c1){
				if (s[x][y]=='R')qwq++;
				ans[x][y]=ch(i);
				nxt(x,y);
			}
		}
		for (int i=1;i<=d2;i++){
			int qwq=0;
			while(qwq<c2){
				if (s[x][y]=='R')qwq++;
				ans[x][y]=ch(d1+i);
				nxt(x,y);
			}
		}
		while(x<=n&&y<=m)ans[x][y]=ch(d1+d2),nxt(x,y);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)putchar(ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}