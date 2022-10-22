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
int T,a,b,c;
void mina(){
	scanf("%d%d%d",&a,&b,&c);
	printf("%d %d %d\n",a+b+c,b+c,c);
}
int main(){scanf("%d",&T);while(T--)mina();return 0;}