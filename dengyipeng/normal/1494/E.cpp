#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 200005
using namespace std;

int n,m,i,j,k,cnt0,cnt1;
map<int,int> e[maxn];

int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		char ch=getchar(); int x,y;
		while (ch!='-'&&ch!='+'&&ch!='?') ch=getchar();
		if (ch=='-'){
			scanf("%d%d",&x,&y);
			if (e[y][x]) {
				cnt0--;
				if (e[y][x]==e[x][y]) cnt1--;
			}
			e[x][y]=0;
		} else 
		if (ch=='+'){
			scanf("%d%d",&x,&y);
			ch=getchar(),ch=getchar(),k=ch-'a'+1;
			if (e[y][x]){
				cnt0++;
				if (e[y][x]==k) cnt1++;
			}
			e[x][y]=k;
		} else {
			scanf("%d",&k);
			int tp;
			if (k&1) tp=cnt0>0;
			else tp=cnt1>0;
			if (tp) printf("YES\n"); else printf("NO\n");
		}
	}
}