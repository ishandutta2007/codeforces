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
int a[502][502],d[502],A[502],B[502];
char s[3];
int Ask(int x,int y){
	if(a[x][y]){
		if(a[x][y]==-1)return 0;
		else return 1;
	}
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='<'){
		a[x][y]=-1;
		a[y][x]=1;
	}
	else{
		a[x][y]=1;
		a[y][x]=-1;
	}
	if(s[0]=='<')return 0;
	return 1;
}
bool bo[502];
bool cmp(int x,int y){
	return d[x]<d[y];
}
struct node{
	int x,y;
	bool operator <(const node&z)const{
		return d[y]<d[z.y];
	}
}c[500];
int main(){
	int t,n,i,j,m=0;
	read(t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(bo,0,sizeof(bo));
		m=0;
		for(i=1;i<=n*2;i+=2){
			Ask(i,i+1);
			++m;
			if(a[i][i+1]==1){
				bo[i]=1;
				B[i+1]=i;
				c[m].x=i;
				c[m].y=i+1;
			}
			else{
				bo[i+1]=1;
				B[i]=i+1;
				c[m].x=i+1;
				c[m].y=i;
			}
		}
		m=0;
		for(i=1;i<=n*2;++i){
			if(bo[i]==0)A[++m]=i;
			for(j=i+1;j<=n*2;++j){
				if(bo[i]==0&&bo[j]==0){
					Ask(i,j);
					if(a[i][j]==1)++d[j];
					else ++d[i];
				}
			}
		}
		sort(A+1,A+1+m,cmp);
		sort(c+1,c+1+m);
		for(i=n-1;i>=2;--i){
			if(Ask(c[i].y,c[i+1].x))continue;
			else{
				int tmp=Ask(c[i].x,c[i+1].x);
				int ta=c[i].x,tb=c[i+1].x;
				if(tmp==0)swap(ta,tb);
				c[i].x=ta;c[i].y=tb;
				for(j=i-1;j>=1;--j){
					if(Ask(c[j].y,c[j+1].y)==0)swap(c[j],c[j+1]);
				}
			}
		}
		puts("!");
		fflush(stdout);
	}
	return 0;
}