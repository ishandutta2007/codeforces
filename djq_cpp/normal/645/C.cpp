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
#include <conio.h>
#include <memory.h>
#include <windows.h>
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
#define rep1(i,n) for(int i=0;i<(n);i++)
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
bool used[100005];
int que[100005],front,rear; 
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	getchar();
	rep(k,n){
		char in=getchar();
		if(in=='0')que[rear++]=k;
	}
	int beg=0,end=c,ans=0x3fffffff;
	while(end<rear){
		int low=beg,high=end;
		while(low<=high){
			int mid=(low+high)/2;
			int dist1=que[mid]-que[beg],dist2=que[end]-que[mid];
			ans=min(ans,max(dist1,dist2));
			if(dist1>dist2)high=mid-1;
			else low=mid+1;
		}
		beg++;end++;
	}
	printf("%d",ans);
	return 0;
}