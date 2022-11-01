#include<bits/stdc++.h>
using namespace std;
char s[4],t[4];
int main()
{
	scanf("%s%s",s,t);
	s[0]-=t[0];
	s[1]-=t[1];
	cout<<max(abs((int)s[0]),abs((int)s[1]))<<endl;
	while(s[0] || s[1])
	{
		if(s[0]>0)s[0]--,printf("L");
		if(s[0]<0)s[0]++,printf("R");
		if(s[1]>0)s[1]--,printf("D");
		if(s[1]<0)s[1]++,printf("U");
		cout<<endl;
	}
	return 0;
}