#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,q,a[5][100005],now;
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=q;i++){
		int r,c;
		scanf("%d%d",&r,&c);
		if (r==1){
			if (a[r][c]==1){
				a[r][c]=0;
				if (a[r+1][c]==1)now--;
				if (a[r+1][c-1]==1)now--;
				if (a[r+1][c+1]==1)now--;
			}
			else{
				a[r][c]=1;
				if (a[r+1][c]==1)now++;
				if (a[r+1][c-1]==1)now++;
				if (a[r+1][c+1]==1)now++;
			}
		}
		if (r==2){
			if (a[r][c]==1){
				a[r][c]=0;
				if (a[r-1][c]==1)now--;
				if (a[r-1][c-1]==1)now--;
				if (a[r-1][c+1]==1)now--;
			}
			else{
				a[r][c]=1;
				if (a[r-1][c]==1)now++;
				if (a[r-1][c-1]==1)now++;
				if (a[r-1][c+1]==1)now++;
			}
		}
		if (now==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}