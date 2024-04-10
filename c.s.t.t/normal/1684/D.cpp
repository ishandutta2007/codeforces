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
int T,n,m,a[200100];
ll sum,res;
void mina(){
	scanf("%d%d",&n,&m),sum=res=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i],a[i]=a[i]-(n-i);
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for(int i=1;i<=m;i++)res+=a[i]+i-1;
	printf("%lld\n",sum-res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}