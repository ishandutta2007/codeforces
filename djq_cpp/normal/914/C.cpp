#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
char ch[1005];
int cnt[1005];
int C[1005][1005];
int s,bs[1005],nn[1005];
int main(){
	int ans=0;
	C[0][0]=1;
	rep1(i,1000){
		C[i][0]=1;
		rep1(j,1000)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%INF;
	}
	scanf("%s",ch);
	scanf("%d",&s);
	int l=strlen(ch),tot=0;
	if(s==0)printf("1\n");
	else if(s==1)printf("%d\n",l-1);
	else{
		rep(i,l)if(ch[i]=='1'){
			for(int j=0;j<l-i;j++)cnt[tot+j]=(cnt[tot+j]+C[l-i-1][j])%INF;
			tot++;
		}
		cnt[tot]++;
		rep1(k,1000){
			bs[k]=bs[k>>1]+(k&1);
			nn[k]=k==1?0:nn[bs[k]]+1;
			if(nn[k]+1==s)ans=(ans+cnt[k])%INF; 
		}
		printf("%d\n",ans);
	}
	return 0;
}