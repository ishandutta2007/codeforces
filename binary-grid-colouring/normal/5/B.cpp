#include<bits/stdc++.h>
using namespace std;
char s[1010][1010];
int main()
{
	int n=0;
	while(gets(s[n]))n++;
	int len=-1;
	for(int i=0;i<n;i++){
		len=max(len,(int)strlen(s[i]));
	}
	for(int i=0;i<len+2;i++)printf("*");//
	cout<<endl;
	int m=0;
	for(int i=0;i<n;i++)
	{
		printf("*");
		int t=len-strlen(s[i]);
		for(int j=0;j<(t+m)/2;j++)printf(" ");
		printf("%s",s[i]);
		for(int j=0;j<( len-strlen(s[i])-(t+m)/2);j++) printf(" ");
		printf("*");
		if(t%2==1)m^=1;
		else m^=0;
	
		printf("\n"); 
	}
	for(int i=0;i<len+2;i++)printf("*");// 

	return 0;
}