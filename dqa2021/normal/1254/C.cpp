#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
int L[1010],R[1010],Ltop,Rtop;
ll S[1010];
int A[1010],B[1010],Atot,Btot;
int ans[1010],anstot;
bool cmp1(int x,int y)
{
	return S[x]<S[y];
}
bool cmp2(int x,int y)
{
	return S[x]>S[y];
}
int main()
{
	scanf("%d",&n);
	int x; ll y;
	for (int i=3;i<=n;i++)
	{
		printf("2 %d %d %d\n",1,2,i);
		fflush(stdout);
		scanf("%d",&x);
		if (x==1) L[++Ltop]=i;
		else R[++Rtop]=i;
		printf("1 %d %d %d\n",1,2,i);
		fflush(stdout);
		scanf("%I64d",&y);  //%I64d!!!
		S[i]=y;
	}
	int midpos=-1;
	for (int i=1;i<=Rtop;i++) if (midpos==-1||S[R[i]]>S[R[midpos]]) midpos=i;
	for (int i=1;i<=Rtop;i++)
	{
		if (i==midpos) continue;
		printf("2 %d %d %d\n",1,R[midpos],R[i]);
		fflush(stdout);
		scanf("%d",&x);
		if (x==1) B[++Btot]=R[i];
		else A[++Atot]=R[i];
	}
	sort(A+1,A+Atot+1,cmp1);
	sort(B+1,B+Btot+1,cmp2);
	ans[++anstot]=1;
	for (int i=1;i<=Atot;i++) ans[++anstot]=A[i];
	if (~midpos) ans[++anstot]=R[midpos];
	for (int i=1;i<=Btot;i++) ans[++anstot]=B[i];
	ans[++anstot]=2;
	
	midpos=-1;
	for (int i=1;i<=Ltop;i++) if (midpos==-1||S[L[i]]>S[L[midpos]]) midpos=i;
	Atot=Btot=0;
	for (int i=1;i<=Ltop;i++)
	{
		if (i==midpos) continue;
		printf("2 %d %d %d\n",1,L[midpos],L[i]);
		fflush(stdout);
		scanf("%d",&x);
		if (x==1) A[++Atot]=L[i];
		else B[++Btot]=L[i];
	}
	sort(A+1,A+Atot+1,cmp1);
	sort(B+1,B+Btot+1,cmp2);
	for (int i=Btot;i;i--) ans[++anstot]=B[i];
	if (~midpos) ans[++anstot]=L[midpos];
	for (int i=Atot;i;i--) ans[++anstot]=A[i];
	printf("0"); for (int i=1;i<=n;i++) printf(" %d",ans[i]); putchar('\n');
	fflush(stdout);
	return 0;
}