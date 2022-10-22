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
const int MX=210;
int N,A[MX],cnt[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	Fr(i,1,N)cnt[A[i]]++;
	Fr(i,0,100)if(cnt[i])printf("%d ",i),--cnt[i];
	Fr(i,0,100)while(cnt[i])printf("%d ",i),--cnt[i];
	putchar('\n');
	Fill(A,0),Fill(cnt,0);
	return 0;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}