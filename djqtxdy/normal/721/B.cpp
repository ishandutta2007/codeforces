#include<cmath>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
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
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL   long long
#define ULL unsigned long long
#define MP make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define INF 2147483647
#define ull unsigned long long
#define VI vector < int >
#define vpii vector < pii >
#define PQ priority_queue
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
using namespace std;
const int Maxn=105;
string a[Maxn];
int len[Maxn];
int main(){
	int n,k;
	cin>>n>>k;
	int m=-1;
	for (int i=0;i<n;i++){
		cin>>a[i];
		len[(int)a[i].length()]++;
		m=max(m,(int)a[i].length());
	}
	string pass;
	cin>>pass;
	m=(int)pass.length();
	for (int i=pass.length()+1;i<Maxn;i++){
		n-=len[i];
	}
	int prev=n-len[m];
	int t=prev+prev/k*5;
	cout<<t+1<<' ';
	t=n+(n-1)/k*5;
	cout<<t<<endl;
	return 0;
}