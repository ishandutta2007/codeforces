/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,fa[200100],l[200100],r[200100];
ll a[200100],res;
void mina(){
	scanf("%d",&n),res=0;
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]),a[i]=0;
	for(int i=n;i;i--){
		a[i]=min(a[i],1ll*r[i]);
		if(a[i]<l[i])a[i]=r[i],res++;
		a[fa[i]]+=a[i];
	}
	printf("%lld\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}