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
int T,n;
ll a[200100];
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		if(a[i]<0){puts("No");return;}
		if(a[i]==0){
			if(count(a+i+1,a+n+1,0)!=n-i){puts("No");return;}
			puts("Yes");return;
		}
		a[i+1]+=a[i],a[i]=0;
	}
	if(a[n]!=0){puts("No");return;}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}