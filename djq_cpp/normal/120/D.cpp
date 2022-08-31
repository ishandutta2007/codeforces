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
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
int cs[2][55],sum[2][55],corns[55][55];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n[2],ans=0,A[3];
	scanf("%d%d",&n[0],&n[1]);
	rep(i,n[0])rep(j,n[1]){
		scanf("%d",&corns[i][j]);
		cs[0][i]+=corns[i][j];
		cs[1][j]+=corns[i][j];
	}
	rep(k,3)scanf("%d",&A[k]);
	rep(i,2){
		sum[i][0]=cs[i][0];
		for(int j=1;j<n[i];j++)
		sum[i][j]=sum[i][j-1]+cs[i][j];
	}
	sort(A,A+3);
	do{
		rep(k,2){
			if(n[k]<3)continue;
			for(int i=1;i<n[k];i++)for(int j=i+1;j<n[k];j++)
			if(sum[k][i-1]==A[0]&&
			   sum[k][j-1]-sum[k][i-1]==A[1]&&
			   sum[k][n[k]-1]-sum[k][j-1]==A[2])
			ans++;
		}
	}while(next_permutation(A,A+3));
	printf("%d",ans);
	return 0;
}