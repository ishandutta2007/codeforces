#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,k;
char s[1004][1004];
char a[1004][1004];
vector<int>vec[2004];
int it[2004],lst[2004];
int calc(int v,int x){
	while(it[v]<vec[v].size()){
		if(vec[v][it[v]]>x)
			return vec[v][it[v]];
		it[v]++;
	}
	return -1;
}
void sol(){
	scanf("%d%d",&n,&k);vector<pii>ans;
	memset(it,0,sizeof(it));
	memset(lst,0,sizeof(lst));
	for(int i=1;i<n+n;i++)vec[i].clear();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=2;i<=n;i++)for(int p=i,q=1;p<=n;p++,q++)
		if(s[p][q]=='1')vec[n-i+1].push_back(q);
	for(int i=1;i<=n;i++)for(int p=1,q=i;q<=n;p++,q++)
		if(s[p][q]=='1')vec[n+i-1].push_back(p);
	for(int i=n-k;~i;i--){
		int pos=calc(n,max(lst[n-1],lst[n+1]));
		if(pos<0){puts("NO");return;}lst[n]=pos;
		ans.push_back({n,pos});
		for(int j=1;j<=i;j++){
			int pa=calc(n-j,max(lst[n-j-1],lst[n-j+1]-1));
			int pb=calc(n+j,max(lst[n+j+1],lst[n+j-1]-1));
			if(pa<0||pb<0){puts("NO");return;}
			lst[n-j]=pa,lst[n+j]=pb;
			ans.push_back({n-j,pa});
			ans.push_back({n+j,pb});
		}
	}
	for(int i=1;i<=n;i++)fill(a[i]+1,a[i]+n+1,'1');
	for(auto[x,y]:ans){
		if(x<n)a[n-x+y][y]='0';
		else a[y][x-n+y]='0';
	}
	puts("YES");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)putchar(a[i][j]);
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}