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
vector<int> ans;
int main(){
	int b;
	cin>>b;
	char c;
	int sum=0;
	while (b--){
		cin>>c;
		if (c=='B') sum++;
		else {
			if (sum!=0){
				ans.push_back(sum);
			}
			sum=0;
		}
		//cout<<sum<<endl;
	}
	if (sum!=0){
		ans.push_back(sum);
	}
	cout<<(int)ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	cout<<endl;
	return 0;
}