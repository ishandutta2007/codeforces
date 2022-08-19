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
char ch[5005];
int ok[5005][5005];
int cnt[128];
void parseL(int pos){
	memset(cnt,0,sizeof(cnt));
	int bp=pos;
	while(ch[pos]){
		cnt[ch[pos]]++;
		if(cnt['(']+cnt['?']<cnt[')'])break;
		ok[bp][pos]++;
		pos++;
	}
}
void parseR(int pos){
	memset(cnt,0,sizeof(cnt));
	int ep=pos;
	while(pos>=0){
		cnt[ch[pos]]++;
		if(cnt[')']+cnt['?']<cnt['('])break;
		ok[pos][ep]++;
		pos--;
	}
}
int main(){
	scanf("%s",ch);
	int L=strlen(ch),ans=0;
	rep(k,L)parseL(k);
	rep(k,L)parseR(k);
	rep(j,L)rep(i,j)
	if(((j-i)&1)&&ok[i][j]==2)ans++;
	printf("%d\n",ans);
	return 0;
}