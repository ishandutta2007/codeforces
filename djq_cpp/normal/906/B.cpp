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
vector<int> ans[100005];
int main(){
	int n,m,cnt;
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)printf("YES\n1\n");
	else if(n==3&&m==3){
		printf("YES\n1 6 8\n7 2 4\n5 9 3\n");
	}else if(n<=3&&m<=3)printf("NO\n");
	else{
		printf("YES\n");
		bool swa=false;
		if(n>m){
			swa=true;
			swap(n,m);
		}
		rep(i,n){
			cnt=0;
			ans[i].resize(m);
			if(m!=4){
				for(int k=i&1;k<m;k+=2)ans[i][cnt++]=k+i*m;
				for(int k=!(i&1);k<m;k+=2)ans[i][cnt++]=k+i*m;
			}else{
				if(i&1)ans[i][0]=2,ans[i][1]=0,ans[i][2]=3,ans[i][3]=1;
				else ans[i][0]=1,ans[i][1]=3,ans[i][2]=0,ans[i][3]=2;
				rep(k,4)ans[i][k]+=i*m;
			}
		}
		if(swa){
			rep(i,m){
				rep(j,n)printf("%d ",ans[j][i]/m+n*(ans[j][i]%m)+1);
				putchar('\n');
			}
		}else{
			rep(i,n){
				rep(j,m)printf("%d ",ans[i][j]+1);
				putchar('\n');
			}
		}
	}
	return 0;
}