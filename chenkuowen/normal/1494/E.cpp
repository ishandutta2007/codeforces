#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
map<int,char> e[N];
char s[5],s1[5];
int main(){
	int n,m,cnt0=0,cnt1=0; scanf("%d%d",&n,&m);
	while(m--){
		scanf("%s",s);
		if(s[0]=='+'){
			int x,y; 
			scanf("%d%d%s",&x,&y,s1);
			e[x][y]=s1[0];
			if(e[x].count(y)&&e[y].count(x)){
				++cnt0; 
				if(e[x][y]==e[y][x]) ++cnt1;
			}
		}else if(s[0]=='-'){
			int x,y; scanf("%d%d",&x,&y);
			if(e[x].count(y)&&e[y].count(x)){
				--cnt0;
				if(e[x][y]==e[y][x]) --cnt1;
			}
			e[x].erase(y);
		}else{
			int k; scanf("%d",&k);
			if(k&1){
				if(cnt0) puts("YES");
				else puts("NO");
			}else{
				if(cnt1) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}