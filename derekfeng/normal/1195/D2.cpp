#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;
int dl[12];
int md[12][10];
long long ans=0;
const long long MOD=998244353;
long long num[40];
int main(){
	for (int i=0;i<=10;i++) dl[i]=0;
	cin>>n;
	num[0]=1;
	for (int i=1;i<40;i++)num[i]=num[i-1]*10%MOD;
	while (n--){
		string s;cin>>s;
		dl[s.size()]++;
		for (int i=0;i<s.size();i++)for (int j=1;j<=10;j++){
			long long o=s[i]-'0';
			long long p=s.size()-i-1;
			if (p<j) ans=(ans+o*num[p*2+1]*dl[j])%MOD;
			if (p>=j) ans=(ans+o*num[p+j]*dl[j])%MOD;
			if (p>=j) ans=(ans+o*num[p+j]*dl[j])%MOD;
			if (p<j) ans=(ans+o*num[p*2]*dl[j])%MOD;
		}
		int u=s.size();
		for (int i=0;i<=10;i++){
			long long ww=0;for(int j=0;j<10;j++)ww+=md[i][j]*j;
			ww%=MOD;
			if (i<u) ans=(ans+num[i*2+1]*ww)%MOD;
			if (i>=u) ans=(ans+num[i+u]*ww)%MOD;
			if (i>=u) ans=(ans+num[i+u]*ww)%MOD;
			if (i<u) ans=(ans+num[i*2]*ww)%MOD;
		}
		for (int i=0;i<s.size();i++)md[s.size()-i-1][s[i]-'0']++;
	}
	cout<<ans;
}