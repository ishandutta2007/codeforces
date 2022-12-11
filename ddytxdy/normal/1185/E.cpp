#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int T,n,m,mm;char c[N][N];bool flag;
struct node{
	int x,y,flag;
}s[26],t[26],a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);flag=mm=0;
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if(c[i][j]=='.')continue;
			int dat=c[i][j]-'a';
			if(!s[dat].x)s[dat]=(node){i,j,0};
			else if(i==s[dat].x){
				if(!s[dat].flag)s[dat].flag=1;
				else if(s[dat].flag!=1)flag=1;
			}
			else if(j==s[dat].y){
				if(!s[dat].flag)s[dat].flag=2;
				else if(s[dat].flag!=2)flag=1;
			}
			else flag=1;
			t[dat]=(node){i,j,0};
		}
		for(int i=25;i>=0;i--){
			if(!s[i].x)continue;
			if(!mm)mm=i+1,a=(node){s[i].x,s[i].y,0};
			if(!s[i].flag)continue;
			if(s[i].flag==1){
				int x=s[i].x;
				for(int j=s[i].y;j<=t[i].y;j++)
					if(c[x][j]=='.'||c[x][j]-'a'<i)flag=1;
			}
			else if(s[i].flag==2){
				int y=s[i].y;
				for(int j=s[i].x;j<=t[i].x;j++)
					if(c[j][y]=='.'||c[j][y]-'a'<i)flag=1;
			}
			else flag=1;
			if(flag)break;
		}
		
		if(flag)puts("NO");
		else{
			puts("YES");printf("%d\n",mm);
			for(int i=0;i<mm;i++){
				if(!s[i].x)printf("%d %d %d %d\n",a.x,a.y,a.x,a.y);
				else printf("%d %d %d %d\n",s[i].x,s[i].y,t[i].x,t[i].y);
			}
		}
	}
	return 0;
}