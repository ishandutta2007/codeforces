#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
int n,m;
vector<string> v;
int a[maxn];
map<int , vector<string> > mp;
ll ans;
bool tp(const string &str)
{
	bool flag0=0,flag1=0;
	int cnt=0,len=str.length();
	for(int i=0;i<len;i++) 
	{
		if(str[i]=='(') cnt++;
		else if(cnt==0)
		{
			flag0=1;
			break;
		}
		else cnt--;
	}
	for(int i=len-1;i>=0;i--) 
	{
		if(str[i]==')') cnt++;
		else if(cnt==0)
		{
			flag1=1;
			break;
		}
		else cnt--;
	}
	return (flag0&&flag1);
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(tp(s)) continue;
		v.push_back(s);
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=0;i<v.size();i++)
	{
		//cout<<v[i]<<endl;
		int len=v[i].length(),cnt=0;
		int flag=0;
		for(j=0;j<len;j++)
		{
			if(v[i][j]==')') cnt--;
			else cnt++;
		}
		a[i]=cnt;
		mp[cnt].push_back(v[i]);
	}
	for(auto tmp=mp.begin();tmp!=mp.end();tmp++)
	{
		if(tmp->first<0) continue;
		if(tmp->first==0)
		{
			int p=tmp->second.size();
			ans+=p/2;
		}
		else
		{
			int p=tmp->first;
			ans+=min(mp[-p].size(),mp[p].size());
		}
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}