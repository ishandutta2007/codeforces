#include<cmath>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define LL long long
#define ll long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int Maxn=5093;
int V[Maxn][Maxn];
int X1[Maxn],X2[Maxn];
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	return z;
}
int p[Maxn],b[Maxn];
int as[Maxn];
bool vis[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		X1[i]=ask(0,i);
		X2[i]=ask(i,0);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			V[i][j]=X1[j]^X2[i]^X1[0];
		}
	}
	int ans=0;
	for (int i=0;i<n;i++){
		p[0]=i;
		for (int j=0;j<n;j++) vis[j]=false;
		bool flag=true;
		for (int j=0;j<n;j++){
			b[j]=p[0]^V[0][j];
		}
		for (int j=1;j<n;j++){
			p[j]=b[0]^V[j][0];
		}
		for (int j=0;j<n;j++){
			if (p[j]>=n || vis[p[j]]){
				flag=false;
			}
			else{
				vis[p[j]]=true;
				if (p[b[j]]!=j) flag=false;
			}
			
		}
		if (flag){
			ans++;
			for (int j=0;j<n;j++){
				as[j]=p[j];
			}
		}
	}
	printf("!\n");
	fflush(stdout);
	printf("%d\n",ans);
	fflush(stdout);
	for (int i=0;i<n;i++){
		printf("%d ",as[i]);
	}
	fflush(stdout);
	return 0;
}