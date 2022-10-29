#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300001;
typedef pair<int,int> pii;
int a[N];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&a[i]);
	}
	if(n==1) puts("-1");
	else if(n==2&&a[1]==a[2]) puts("-1");
	else
	{
		cout<<1<<endl;
		int minn=100000,pos=-1;
		for(int i=1;i<=n;i++)
		{
			if(minn>a[i]) pos=i,minn=a[i];
		}
		cout<<pos<<endl;
	}
	return 0;
}