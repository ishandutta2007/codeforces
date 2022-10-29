#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int T,n;
char s[N];
vector<int> a,b;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		a.clear(); b.clear();
		scanf("%d",&n);
		scanf("%s",s+1);
		int top=n,num=1;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='<')
			{
				num++;
			}
			else
			{
				for(int j=top-num+1;j<=top;j++) a.push_back(j);
				top-=num; num=1;
			}
		}
		for(int j=top-num+1;j<=top;j++) a.push_back(j);
		
		top=1;num=1;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='>')
			{
				num++;
			}
			else
			{
				for(int j=top+num-1;j>=top;j--) b.push_back(j);
				top+=num; num=1;
			}
		}
		for(int j=top+num-1;j>=top;j--) b.push_back(j);
		
		for(int i=0;i<n;i++) printf("%d ",a[i]); puts("");
		for(int i=0;i<n;i++) printf("%d ",b[i]); puts("");
	}
	return 0;
}