#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 200005
using namespace std;

int n,i,j,k,opr[maxn][2],ans[maxn];
struct arr{
	int x;
	arr(int _x=0){x=_x;}
};
int operator<(arr a,arr b){return a.x>b.x;}
priority_queue<arr> q;
char ch;

int main(){
	scanf("%d",&n),ch=getchar();
	for(i=1;i<=2*n;i++){
		while (ch!='+'&&ch!='-') ch=getchar();
		if (ch=='+') opr[i][0]=1,ch=getchar();
		else opr[i][0]=2,scanf("%d",&opr[i][1]),ch=getchar();
	}
	for(i=2*n;i>=1;i--) if (opr[i][0]==1){
		if (q.empty()) printf("NO\n"),exit(0);
		ans[++ans[0]]=q.top().x,q.pop();
	} else {
		if (q.empty()) q.push(arr(opr[i][1]));
		else {
			if (q.top().x<opr[i][1]) printf("NO\n"),exit(0);
			q.push(arr(opr[i][1]));
		}
	}
	printf("YES\n");
	for(i=n;i>=1;i--) printf("%d ",ans[i]);
}