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
ll sum1,sum2;
int main()
{
	int i,j;
	read(n);
	for(i=0;i<n;i++) 
	{
		read(m);
		sum1+=m;
	}
	for(i=0;i<n;i++)
	{
		read(m);
		sum2+=m;
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	if(sum1<sum2) cout<<"No";
	else cout<<"Yes";
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}