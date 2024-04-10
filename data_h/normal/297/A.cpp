#include<cstdio>
#include<cstring>
#define MaxN 100010
using namespace std;
char S1[MaxN],S2[MaxN];
int N,M,cnt1,cnt2;
int main(){
	int i,j;
	scanf("%s",&S1);
	scanf("%s",&S2);
	N=strlen(S1);
	M=strlen(S2);
	for(i=0;i<N;++i)
		if(S1[i]=='1')
			++cnt1;
	for(i=0;i<M;++i)
		if(S2[i]=='1')
			++cnt2;
	if(cnt1%2==1)
		++cnt1;
	if(cnt1>=cnt2)
		puts("YES");
	else
		puts("NO");
	return 0;
}