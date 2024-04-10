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
ll cT[100005],eT[100005];
int main(){
	int n;
	ll Tbeg,Tend,Tper;
	ll res=ll(INF)*INF,ans=0LL;
	scanf("%I64d%I64d%I64d%d",&Tbeg,&Tend,&Tper,&n);
	cT[0]=0LL;
	eT[0]=Tbeg-1LL;
	rep1(k,n){
		scanf("%I64d",&cT[k]);
		eT[k]=max(eT[k-1]+Tper,cT[k]+Tper-1LL);
	}
	if(eT[n]+Tper<Tend){
		printf("%I64d",Tend-Tper);
		return 0;
	}
	for(int k=1;k<=n;k++){
		if(cT[k]==cT[k-1])continue;
		if(cT[k]==0)continue;
		if(eT[k-1]+Tper>=Tend)continue;
		long long cur=eT[k-1]-cT[k]+2LL;
		if(cur<0){
			res=0;
			ans=eT[k-1]+1;
		}else if(cur<res){
			res=cur;
			ans=cT[k]-1;
		}
	}
	printf("%I64d",ans);
	return 0;
}