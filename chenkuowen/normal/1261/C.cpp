#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
vector<vector<int> > s,e,a;
char ss[MAX_N];
int n,m;
vector<pair<int,int> > ans;
int calc(int x,int y,int x1,int y1){
	x1=min(x1,n); y1=min(y1,m);
//	printf("<%d %d %d %d>\n",x,y,x1,y1);
	return s[x1][y1]-s[x1][y-1]-s[x-1][y1]+s[x-1][y-1];
}
bool check(int std){
	ans.clear(); s.clear(); e.clear();
	s.resize(n+2);  e.resize(n+2);
	for(int i=0;i<=n;++i){
		s[i].resize(m+2);
		e[i].resize(m+2);
		fill(e[i].begin(),e[i].end(),0);
		fill(s[i].begin(),s[i].end(),0);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(calc(i,j,i+std+std,j+std+std)==1ll*(std+std+1)*(std+std+1)){
		//		printf("{%d %d %d %d}\n",i,j,i+std+std,j+std+std);
				e[i][j]+=1;
				if(i+std+std+1<=n)	
					e[i+std+std+1][j]-=1;
				if(j+std+std+1<=m)
					e[i][j+std+std+1]-=1;
				if(i+std+std+1<=n&&j+std+std+1<=m)
					e[i+std+std+1][j+std+std+1]+=1;
				ans.push_back(make_pair(i+std,j+std));
			}
	}
/*	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j)
			printf("<%d>",e[i][j]);
		puts("");
	}
*/	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			e[i][j]=e[i][j]+e[i-1][j]
				+e[i][j-1]-e[i-1][j-1];
			if(e[i][j]==0&&a[i][j]==1) return false;
		}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n+2); 
	for(int i=0;i<=n;++i) a[i].resize(m+2);
	for(int i=1;i<=n;++i){
		scanf("%s",ss+1);
		for(int j=1;j<=m;++j)
			if(ss[j]=='X') a[i][j]=1;
			else a[i][j]=0;
	}
	int left=0,right=min(n,m);
	while(left<right){
		int mid=left+right+1>>1;
		if(check(mid)) left=mid;
		else right=mid-1;
	}
	check(left);
//	printf("[%d]",check(left));
	for(int i=0;i<ans.size();++i) 
		a[ans[i].first][ans[i].second]=2;
	printf("%d\n",left);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(a[i][j]==2) putchar('X');
			else putchar('.');
		puts("");
	}
	return 0;
}