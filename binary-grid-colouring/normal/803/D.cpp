#include <bits/stdc++.h>
using namespace std;
int b[1234567];
int cnt=0;
char s[1234567];
int k;
bool check(int x)
{
	int now = 0;
	int t = 0;
	for(int i=0;i<cnt;i++)
	{
		if(b[i]+now<=x)now+=b[i];
		else
		{
			t++;
			now = 0;
			now+=b[i];
			if(now>x)return false;
		}
	}
	if(t >= k)return false;
	else return true;
}
int main()
{
	cin>>k;
	getchar();
	gets(s);
	int len =strlen(s);
	for(int i=0;i<len;i++)
	{
		b[cnt]++;
		if(s[i]==' ' || s[i]=='-')cnt++;
	}
	cnt++;
	int l=0,r=len+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	return 0;
}