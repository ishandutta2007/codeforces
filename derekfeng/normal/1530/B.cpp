#include <bits/stdc++.h>
using namespace std;
int T,h,w;
char c[22][22];
int main(){
	cin>>T;	
	while(T--){
		cin>>h>>w;
		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)c[i][j]='0';
		if(h&1){
			if(w&1){
				for(int i=1;i<=w;i+=2)c[1][i]=c[h][i]='1';
				for(int i=1;i<=h;i+=2)c[i][1]=c[i][w]='1';
			}else{
				for(int i=2;i<=w;i+=2)c[1][i]='1';
				for(int i=1;i<=w;i+=2)c[h][i]='1';
				for(int i=3;i<=h-2;i+=2)c[i][1]='1',c[i][w]='1';
			}
		}else{
			if(w&1){
				for(int i=2;i<=h;i+=2)c[i][1]='1';
				for(int i=1;i<=h;i+=2)c[i][w]='1';
				for(int i=3;i<=w-2;i+=2)c[1][i]=c[h][i]='1';
			}else{
				for(int i=2;i<=w-2;i+=2)c[1][i]='1';
				for(int i=2;i<=h-2;i+=2)c[i][w]='1';
				for(int i=3;i<=h-1;i+=2)c[i][1]='1';
				for(int i=3;i<=w-1;i+=2)c[h][i]='1';	
			}
		}
		for(int i=1;i<=h;i++,puts(""))for(int j=1;j<=w;j++)cout<<c[i][j];
		puts("");
	}
}