#include<bits/stdc++.h>
using namespace std;

const int p=1000000007;
int N,cntsuf0;
char s[1000005];
int A[1000005];
int stk[1000005],len,ans[1000005];

int main(){
	scanf("%s",s+1);N=strlen(s+1);
	while(s[N]=='0') cntsuf0++,N--;
	if(!N){printf("%d\n",cntsuf0);return 0;}
	
	int ANS=0,SUM=0;
	for(int i=N;i;i--){
		int j=i;
		while(s[j-1]=='0') j--;
		A[i]=i-j,ans[i]=SUM+1;
		while(len&&A[stk[len]]<A[i])
			SUM=(SUM+1LL*ans[stk[len]]*(p-A[stk[len]]-1)%p+1LL*ans[stk[len-1]]*(A[stk[len]]+1)%p)%p,
			len--;
		SUM=(SUM+1LL*ans[i]*(A[i]+1)%p+1LL*ans[stk[len]]*(p-A[i]-1)%p)%p;
		stk[++len]=i;
		if(j==1) ANS=1LL*ans[i]*(A[i]+1)%p;
		i=j;
	}
	printf("%d\n",1LL*ANS*(cntsuf0+1)%p);
	return 0;
}