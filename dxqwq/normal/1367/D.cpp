#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		string s;
		cin>>s;
		int n=read();
		string ans(n,'.');
		int a[n];
		for(int &i:a) cin>>i;
		char now='z';
		while(now>='a') 
		{
			vector<int> v;
			for(int i=0; i<n; ++i) 
			{
				if(ans[i]!='.') continue;
				int tmp=0;
				for(int j=0; j<n; ++j) if(ans[j]!='.') tmp+=abs(i-j);
				if(tmp==a[i]) v.push_back(i);
			}
			while(count(s.begin(),s.end(),now)<v.size()) --now;
			int sz=v.size();
			for(int i=0; i<sz; i++) ans[v[i]]=now;
			--now;
		}
		cout<<ans<<endl;
	}
	return 0;
}