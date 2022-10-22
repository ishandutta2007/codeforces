#include<bits/stdc++.h>
using namespace std;
#define N 1000000
#define M 1000000
#define pb push_back
int a[M+1],b[M+1],deg[N+1],ord[M+1];
vector<int> ans;
bool cmp(int x,int y){
	return min(deg[a[x]],deg[b[x]])<min(deg[a[y]],deg[b[y]]);
}
int main(){
	int n,m,i;scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d%d",a+i,b+i),deg[a[i]]++,deg[b[i]]++,ord[i]=i;
	for(i=1;i<=n;i++)deg[i]=deg[i]-(deg[i]+1>>1);
	sort(ord+1,ord+m+1,cmp);
//	for(i=1;i<=m;i++)cout<<ord[i]<<" ";puts("");
	for(i=1;i<=m;i++)
		if(deg[a[ord[i]]]&&deg[b[ord[i]]])deg[a[ord[i]]]--,deg[b[ord[i]]]--;
		else ans.pb(ord[i]);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)printf("%d %d\n",a[ans[i]],b[ans[i]]);
	return 0;
}
/*1
6 6
1 2
2 3
3 4
4 5
5 3
6 5
*/
/*2
10 20
4 3
6 5
4 5
10 8
4 8
5 8
10 4
9 5
5 1
3 8
1 2
4 7
1 4
10 7
1 7
6 1
9 6
3 9
7 9
6 2
*/