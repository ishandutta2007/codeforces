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
string s;
int k;
int h[205];
int cnt1,cnt2;
int main()
{
	int i,j;
	cin>>s;
	cin>>k;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	int len=s.length(),leng=s.length();
	for(i=0;i<leng;i++) h[i]=1;
	for(i=0;i<leng;i++) 
		if(s[i]=='?'||s[i]=='*') len--;
	for(i=0;i<leng-1;i++)
	{
		if(s[i+1]=='?'||s[i+1]=='*')
		{
			if(len>k) 
			{
				h[i]=0;
				len--;
			}
			else if(s[i+1]=='*')
			{
				h[i]+=k-len;
				len=k;
			}
		}
	}
	if(len!=k) 
	{
		cout<<"Impossible";
		return 0;
	}
	for(i=0;i<leng;i++)
	{
		if(s[i]=='?'||s[i]=='*') continue;
		while(h[i]--) putchar(s[i]);
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}