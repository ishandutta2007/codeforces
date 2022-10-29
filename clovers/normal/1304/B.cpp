#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=100010;

map<string,int> mp;
char s[201][101];
int n,m;
int bl[201];
vector<int> a,b;
int c=-1,sum=0;

int main()
{
	memset(bl,0,sizeof(bl));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",s[i]+1);
		string tmp1,tmp2;
		for(int j=m;j>=1;j--) tmp2=tmp2+s[i][j];
		for(int j=1;j<=m;j++) tmp1=tmp1+s[i][j];
		map<string,int> :: iterator it=mp.find(tmp2);
		if(it!=mp.end()) 
		{
			int x=it->second;
			bl[i]=1;
			bl[x]=1;
			a.push_back(i);
			b.push_back(x);
			mp.erase(it);
		}
		else{
			mp[tmp1]=i;
		}
	}
	for(int i=1;i<=n;i++) 
	{
		if(bl[i]) 
		{
			sum+=m;
			continue;
		}
		int p=1;
		for(int j=1;j<=m/2;j++) if(s[i][j]!=s[i][m-j+1]) p=0;
		if(p==1) c=i;
	}
	if(c!=-1) sum+=m;
	printf("%d\n",sum);
	for(int i=0;i<(int)a.size();i++) printf("%s",s[a[i]]+1);
	if(c!=-1) printf("%s",s[c]+1);
	for(int i=(int)b.size()-1;i>=0;i--) printf("%s",s[b[i]]+1);
	
	return 0;
}