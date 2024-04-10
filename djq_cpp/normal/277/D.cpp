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
const long double EPS=1e-9;
struct task{
	long double ps,pl,prb;
	int ts,tl;
	bool operator <(const task& oth)const{
		return tl*oth.prb-tl*prb*oth.prb<oth.tl*prb-oth.tl*oth.prb*prb;
	}
}pro[1005];
long double sc[1005][1565],t[1005][1565];
void upd(int i,int j,long double csc,long double ct){
	if(csc-sc[i][j]>EPS||csc-sc[i][j]>-EPS&&t[i][j]>ct){
		sc[i][j]=csc;
		t[i][j]=ct;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,lim,nj;
	cin>>n>>lim;
	rep(k,n){
		cin>>pro[k].ps>>pro[k].pl>>pro[k].ts>>pro[k].tl>>pro[k].prb;
		pro[k].prb=1.0-pro[k].prb;
	}
	sort(pro,pro+n);
	rep(i,n)for(int j=0;j<=lim;j++){
		upd(i+1,j,sc[i][j],t[i][j]);
		if((nj=j+pro[i].ts)>lim)continue;
		upd(i+1,nj,sc[i][j]+pro[i].ps,t[i][j]+pro[i].ts);
		if((nj=j+pro[i].ts+pro[i].tl)>lim)continue;
		upd(i+1,nj,sc[i][j]+pro[i].ps+pro[i].pl*pro[i].prb,(t[i][j]+pro[i].ts)*(1.0-pro[i].prb)+nj*pro[i].prb);
	}
	for(int k=0;k<=lim;k++)upd(0,0,sc[n][k],t[n][k]);
	cout<<fixed<<setprecision(10)<<sc[0][0]<<' '<<t[0][0];
	return 0;
}