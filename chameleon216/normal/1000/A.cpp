#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <string>
#include <map>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
char S[10];
map<string,int> mp;
int N;

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%s",S),++mp[S];
	Fr(i,1,N)scanf("%s",S),--mp[S];
	int ans=0;
	for(auto i:mp)if(i.second>0)ans+=i.second;
	printf("%d\n",ans);
	return 0;
}