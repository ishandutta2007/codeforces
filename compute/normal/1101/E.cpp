#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char op[2];
	int h=0,w=0;
	while(n--)
	{
		scanf("%s",op);
		if(op[0]=='+')
		{
			int curh,curw;
			scanf("%d%d",&curh,&curw);
			if(curh<curw) swap(curh,curw);
			h=max(h,curh);
			w=max(w,curw);
		}
		else{
			int curh,curw;
			scanf("%d%d",&curh,&curw);
			if(curh<curw) swap(curh,curw);
			if(curh>=h&&curw>=w) puts("YES");
			else puts("NO");
		}
	}
}