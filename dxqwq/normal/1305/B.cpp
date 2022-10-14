#include <bits/stdc++.h>
using namespace std;
char str[200005];
vector <int> vt;
int main() 
{
	scanf("%s",str+1);
	int n=strlen(str+1);
	int l=1,r=n;
	while (l<=r) 
	{
		while (l<=n&&str[l]==')') l++;
		while (r&&str[r]=='(') r--;
		if (l>r) break;
		vt.push_back(l);
		vt.push_back(r);
		l++;
		r--;
	}
	if (!vt.size()) puts("0");
	else 
	{
		puts("1");
		sort(vt.begin(),vt.end());
		printf("%d\n",(int)vt.size());
		for(int i=0; i<vt.size(); i++) printf("%d ",vt[i]);
		printf("\n");
	}
	return 0;
}