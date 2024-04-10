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
int ans[1005];
bool isp[1005];
void _init(){
	memset(isp,1,sizeof(isp));
	for (int i=2;i<1005;i++){
		if (isp[i]){
			for (int j=i+i;j<1005;j+=i){
				isp[j]=false;
			}
		}
	}
}
int main(){
_init(); 
	for (int i=1;i<=1000;i++) ans[i]=-1;
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=i;j++){
			if (!isp[j] && ans[i-j]!=-1){
				ans[i]=max(ans[i],ans[i-j]+1);
			}
		}
	}
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		if (n<=1000){
			printf("%d\n",ans[n]);
		}
		else{
			int x=(n-500)/4;
			n-=x*4;
			printf("%d\n",ans[n]+x);
		}
	}
}