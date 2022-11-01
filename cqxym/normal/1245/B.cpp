#include<stdio.h>
#include<iostream>
using namespace std;
#define R register int
string s;
char ans[101];
inline void Solve(){
	int a,b,c,n,t=0;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	cin>>s;
	for(R i=0;i<n;i++){
		ans[i]='1';
		if(s[i]=='R'){
			if(b>0){
				b--;
				t++;
				ans[i]='P';
			}
		}else if(s[i]=='S'){
			if(a>0){
				a--;
				t++;
				ans[i]='R';
			}
		}else if(s[i]=='P'){
			if(c>0){
				c--;
				t++;
				ans[i]='S';
			}
		}
	}
	if(t>=(n+1>>1)){
		puts("YES");
		for(R i=0;i<n;i++){
			if(ans[i]=='1'){
				if(a>0){
					printf("R");
					a--;
				}else if(b>0){
					printf("P");
					b--;
				}else if(c>0){
					printf("S");
					c--;
				}
			}else{
				printf("%c",ans[i]);
			}
		}
		puts("");
	}else{
		puts("NO");
	}
}
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}