#include<bits/stdc++.h>
const int N=505;
using namespace std;

int ans[N][N],a[N],n;

void mv(int&x,int&y){
	if(y<n&&!ans[x][y+1])y++;
	else x--;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--){
		int x=i,y=i;
		for(int j=1;j<=a[i];j++)
			ans[x][y]=a[i],mv(x,y);
	}
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=i;j++)
			printf("%d ",ans[j][i]);
}