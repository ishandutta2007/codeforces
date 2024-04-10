#include<bits/stdc++.h>
using namespace std;
int a[1003],nxt[1003],pre[1003];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	char ch=getchar();
	for(int i=1; i<=n; i++) ch=getchar(),a[i]=(int)ch-(int)'a'+1,nxt[i]=i+1,pre[i]=i-1;
	int head=0,tail=n+1;
	nxt[0]=1,pre[n+1]=n;
	for(int i=26; i>1; i--) 
	{
		int now=nxt[head];
		while(now!=tail) 
		{
			if((a[pre[now]]==i-1 || a[nxt[now]]==i-1) && a[now]==i) 
			{
				pre[nxt[now]]=pre[now],nxt[pre[now]]=nxt[now],ans++;
				if(now==head) nxt[now]=head;
				if(now==tail) pre[now]=tail;
				if(now==head) now=nxt[now]; else now=pre[now];
			}
			else
			now=nxt[now]; 
		}
	}
	cout<<ans;
	return 0;
}