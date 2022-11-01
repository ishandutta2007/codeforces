#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=105;
int n,tp;char str[N],st[N];
int main(){
	scanf("%d",&n);scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		st[++tp]=str[i];
		if(tp>1&&st[tp-1]!='D'&&st[tp-1]!=st[tp])st[--tp]='D';
	}
	printf("%d\n",tp);
	return 0;
}