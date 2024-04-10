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
int pows[1000005];
bool ispri[1000005];
vector<int> pri;
const int LIM=1e6;
void init_pri(){
	for(int k=2;k<=LIM;k++)ispri[k]=true;
	for(int k=2;k*k<=LIM;k++){
		if(!ispri[k])continue;
		for(int j=k*2;j<=LIM;j+=k)ispri[j]=false;
	}
	for(int k=2;k<=LIM;k++)
	if(ispri[k])pri.push_back(k);
}
void to_pris(int n){
	int ptr=0,pn=0;
	while(1){
		pn=pri[ptr];
		if(pn*pn>n)break;
		int t=0;
		while(n%pn==0){
			n/=pn;
			t++;
		}
		pows[pn]=max(pows[pn],t);
		ptr++;
	}
	if(n>1)pows[n]=max(pows[n],1);
}
bool chk_pris(int n){
	int ptr=0,pn=0;
	while(1){
		pn=pri[ptr];
		if(pn*pn>n)break;
		int t=0;
		while(n%pn==0){
			n/=pn;
			t++;
		}
		if(pows[pn]<t)return false;
		ptr++;
	}
	return n==1||pows[n];
}
int main(){
	init_pri();
	int n,c,num;
	scanf("%d%d",&n,&c);
	rep(k,n){
		scanf("%d",&num);
		to_pris(num);
	}
	if(chk_pris(c))printf("Yes");
	else printf("No");
}