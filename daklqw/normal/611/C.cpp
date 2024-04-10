#include <iostream>
using namespace std;
int pre[2][510][510],n,m,q,x1,y1,x2,y2;
bool t[510][510];char x;
void gc(){while(x=getchar(),x!='#'&&x!='.');}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			gc(),t[i][j]=x=='.';
	for(int i=1;i<=n;++i)
		for(int j=2;j<=m;++j)
			pre[0][i][j]=pre[0][i][j-1]+(t[i][j]==t[i][j-1]&&t[i][j]==true);
	for(int j=1;j<=m;++j)
		for(int i=2;i<=n;++i)
			pre[1][i][j]=pre[1][i-1][j]+(t[i][j]==t[i-1][j]&&t[i][j]==true);
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
		long long ans=0;
		for(int i=y1;i<=y2;++i)ans+=pre[0][i][x2]-pre[0][i][x1];
		for(int i=x1;i<=x2;++i)ans+=pre[1][y2][i]-pre[1][y1][i];
		printf("%I64d\n",ans);
	}
	return 0;
}