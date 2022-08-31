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
#define cindy(i,n) for(int i=0;i<(n);i++)
#define cindy1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
string S[100005];
vector<pair<pii,int> > tot;
char ans[2000005];
int main(){
	ios::sync_with_stdio(false);
	int n,t,x;
	cin>>n;
	cindy(i,n){
		cin>>S[i];
		cin>>t;
		cindy(j,t){
			cin>>x;x--;
			tot.push_back(MP(MP(x,x+S[i].length()),i));
		}
	}
	sort(tot.begin(),tot.end());
	int SZ=0;
	for(int k=tot[0].first.first;k<tot[0].first.second;k++){
		ans[k]=S[tot[0].second][k-tot[0].first.first];
		SZ=max(SZ,k);
	}
	int rtm=0;
	for(int i=1;i<tot.size();i++){
		rtm=max(rtm,tot[i-1].first.second);
		for(int j=max(tot[i].first.first,rtm);j<tot[i].first.second;j++){
			ans[j]=S[tot[i].second][j-tot[i].first.first];
			SZ=max(SZ,j);
		}
	}
	SZ++;
	cindy(k,SZ)if(!isalpha(ans[k]))ans[k]='a';
	printf("%s",ans);
	return 0;
}