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
char seat[1005][10];
bool have=false;
void getnew(int id,int a,int b){
	if(have)return;
	if(seat[id][a]=='O'&&seat[id][b]=='O'){
		seat[id][a]=seat[id][b]='+';
		have=true;
	}
}
int main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%s",seat[i]);
		getnew(i,0,1);getnew(i,3,4);
	}
	getchar();
	if(have){
		puts("YES");
		rep(i,n)puts(seat[i]);
	}else puts("NO");
	return 0;
}