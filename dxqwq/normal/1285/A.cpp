#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l=0,r=0;
	char ch;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) 
	{
		scanf("%c",&ch);
		if(ch=='L') l++; else r++;
	}
	cout<<l+r+1;
	return 0;
}