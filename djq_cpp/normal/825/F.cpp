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
char ch[8005];
int n,dp[8005];
unsigned long long prehash[3][8005],hbase[3][8005],hrev[3][8005];
bool used[8005];
int lg10[8005];
unsigned long long HASH[3]={1723333ull,19260817ull,1000000007ull},HMOD[3]={1000000007ull,998244353ull,1000000009ull};
unsigned long long POWER(unsigned long long from,unsigned long long T,unsigned long long mods){
	if(T==0ull)return 1ull;
	unsigned long long div2=POWER(from,T>>1,mods);
	div2=div2*div2%mods;
	return (T&1)?div2*from%mods:div2%mods;
}
void init_hash(int CURH){
	hbase[CURH][0]=1ull;
	for(int k=1;k<n;k++)hbase[CURH][k]=hbase[CURH][k-1]*HASH[CURH]%HMOD[CURH];
	hrev[CURH][0]=1ull;
	hrev[CURH][1]=POWER(HASH[CURH],HMOD[CURH]-2,HMOD[CURH]);
	for(int k=2;k<n;k++)hrev[CURH][k]=(hrev[CURH][k-1]*hrev[CURH][1])%HMOD[CURH];
	rep1(k,n)prehash[CURH][k]=(prehash[CURH][k-1]+ch[k]*hbase[CURH][k-1])%HMOD[CURH];
}
//(l,r]
unsigned long long get_hash(int CURH,int l,int r){
	return (prehash[CURH][r]+HMOD[CURH]-prehash[CURH][l])*hrev[CURH][l]%HMOD[CURH];
}
int main(){
	rep1(k,8000)lg10[k]=lg10[k/10]+1;
	scanf("%s",ch+1);
	n=strlen(ch+1);
	rep(k,3)init_hash(k);
	dp[0]=0;
	rep1(i,n){
		dp[i]=INF;
		memset(used,false,sizeof(used));
		rep1(j,i){
			if(used[j])continue;
			used[j]=true;
			unsigned long long curh[3];
			rep(k,3)curh[k]=get_hash(k,i-j,i);
			dp[i]=min(dp[i],dp[i-j]+1+j);
			for(int cnt=2;cnt*j<=i;cnt++){
				bool f=true;
				rep(k,3)if(get_hash(k,i-j*cnt,i+j-j*cnt)!=curh[k])f=false;
				if(!f)break;
				used[j*cnt]=true;
				dp[i]=min(dp[i],dp[i-j*cnt]+lg10[cnt]+j);
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}