#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,k,a[N][N];
set<int>s[N];
set<int>::iterator it;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=2)s[j].insert(i);
		}
	for(int i=1,y,x;i<=k;i++){
		scanf("%d",&y);
		x=1;
		while(x<=n){
			it=s[y].lower_bound(x);
			if(it==s[y].end()){printf("%d ",y);break;}
			int xx=*it;
			int p=a[xx][y];a[xx][y]=2;
			s[y].erase(it);
			if(p==1)y++;
			else y--;
			x=xx;
		}
	}
	return 0;
}