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
char a[100];int tmp;
int main()
{
	int i,j;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	cin>>s;
	int len=s.length();
	int p1=0,p2=len-1;
	if(len&1)
	{
		while(p1<=p2)
		{
			a[tmp++]=s[p1++];
			a[tmp++]=s[p2--];
		}
	}
	else
	{
		while(p1<=p2)
		{
			a[tmp++]=s[p2--];
			a[tmp++]=s[p1++];
		}
	}
	for(int i=len-1;i>=0;i--) cout<<a[i];
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}