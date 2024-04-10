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
int T,n;
char s[20];
void mina(){
	scanf("%s",s),n=strlen(s);
	if(n==2)printf("%c\n",s[n-1]);else printf("%c\n",*min_element(s,s+n));
}
int main(){scanf("%d",&T);while(T--)mina();return 0;}