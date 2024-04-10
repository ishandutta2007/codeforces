#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int n,t[N];
set<int> st2,st4,st6,st8;

int main()
{
	memset(t,0,sizeof(t));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		t[x]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(t[i]>=8) st8.insert(i);
		else if(t[i]>=6) st6.insert(i);
		else if(t[i]>=4) st4.insert(i);
		else if(t[i]>=2) st2.insert(i);
	}
	int q; cin>>q;
	while(q--)
	{
		char opt[2]; int x;
		scanf("%s",opt);
		scanf("%d",&x);
		if(opt[0]=='+')
		{
			t[x]++;
			if(t[x]==2) st2.insert(x);
			if(t[x]==4) st2.erase(x),st4.insert(x);
			if(t[x]==6) st4.erase(x),st6.insert(x);
			if(t[x]==8) st6.erase(x),st8.insert(x);
		}
		else
		{
			t[x]--;
			if(t[x]==1) st2.erase(x);
			if(t[x]==3) st4.erase(x),st2.insert(x);
			if(t[x]==5) st6.erase(x),st4.insert(x);
			if(t[x]==7) st8.erase(x),st6.insert(x);
		}
		//cout<<(int)st8.size()<<" "<<(int)st6.size()<<" "<<(int)st4.size()<<" "<<(int)st2.size()<<endl;
		if((int)st8.size()>0)
		{
			puts("YES");
			continue;
		}
		if((int)st6.size()>=2||(int)st4.size()>=2)
		{
			puts("YES");
			continue;
		}
		if((int)st6.size()>0&&((int)st4.size()>0||(int)st2.size()>0))
		{
			puts("YES");
			continue;
		}
		if((int)st4.size()>0&&(int)st2.size()>=2)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}