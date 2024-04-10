#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=105;
int N;
int a[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",a+i);
	sort(a+1,a+1+N);
	int x=0,y=0;
	Fl(i,N,1)
	{
		if(x>y)swap(x,y);
		x+=a[i];
	}
	printf(x==y?"YES\n":"NO\n");
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}