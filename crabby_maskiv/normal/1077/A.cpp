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
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
int T;
int main()
{
	int i,j;
	cin>>T;
	#ifdef TIME
		clock_t ST=clock();
	#endif
	while(T--)
	{
		ll a,b,k;
		cin>>a>>b>>k;
		if(k%2) cout<<(a-b)*(k/2)+a<<endl;
		else cout<<(a-b)*(k/2)<<endl;
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}