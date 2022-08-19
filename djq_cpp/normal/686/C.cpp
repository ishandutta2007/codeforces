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
int ns[10],nown[10],used[7],len,nl;
bool getbase7(int num,int &len,int str[]){
	do{
		if(len>7)return false;
		str[len++]=num%7;
		num/=7;
	}while(num);
	return true;
}
bool plus1(){
	int car=0;
	while(nown[car]==6){
		nown[car]=0;
		car++;
		if(car>=len)return false;
	}
	nown[car]++;
	return true;
}
bool same(){
	rep(k,7)used[k]=0;
	rep(k,len){
		used[nown[k]]++;
		if(used[nown[k]]>1)return true;
	}
	return false;
}
bool check(){
	for(int k=len-1;k>=nl;k--){
		if(nown[k]<ns[k])break;
		else if(nown[k]>ns[k])return false;
	}
	for(int k=nl-1;k>=0;k--){
		if(nown[k]<ns[k])break;
		else if(nown[k]>ns[k])return false;
	}
	return true;
}
void endup(){
	putchar('0');
	exit(0);
}
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	n--;m--;
	if(!getbase7(n,len,ns))endup();
	nl=len;
	if(!getbase7(m,len,ns))endup();
	do if(!same()&&check())ans++;
	while(plus1());
	printf("%d",ans);
	return 0;
}