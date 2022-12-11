#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n;
struct Rec{
	int x,y;
}rec[500010]; int top;
void solve(int l,int r){
	if (l==r) return;
	int mid=l+r>>1;
	solve(l,mid); solve(mid+1,r);
	int t=mid-l+1;
	for (int i=1;i<=t;i++){
		rec[++top]=(Rec){l+i-1,mid+i};
//		printf("test %d %d  %d\n",l,mid+1,i);
	}
}
int main()
{
	n=read();
	int len=1;
	while (len*2<=n) len*=2;
	solve(1,len); solve(n-len+1,n);
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d %d\n",rec[i].x,rec[i].y);
}