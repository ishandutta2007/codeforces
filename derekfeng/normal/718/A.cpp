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
#define inf 0x3f3f3f3f
const int maxn=2e5+10;
char s[maxn];
int dp[maxn];
int main(){
	int n,t;
	scanf ("%d%d",&n,&t);
	scanf ("%s",s);
	memset (dp,0x3f,sizeof(dp));
	int pos;
	for (int i=n-1;i>=0;i--){
		if (s[i]>='5' && s[i]<='9'){
			dp[i-1]=1;
		}
		else if (s[i]=='4'){
			dp[i-1]=min(inf,dp[i]+1);
		}
		else if (s[i]=='.'){
			pos=i;
			break;
		}
	}
	int len=n;
	if (dp[pos]<=t){
		len=pos;
		s[pos-1]++;
		int cr;
		while (s[pos-1]>'9'){
			s[pos-1]='0';
			cr=1;
			pos--;
			if (pos-1>=0) s[pos-1]++;
			else break;
		}
		if (pos-1<0){
			printf("1");
		}
		for (int i=0;i<len;i++)
			printf("%c",s[i]);
	}
	else{
		while (dp[pos]>t && pos<n) pos++;
		if (pos>=n) printf("%s",s);
		else{
			s[pos]++;
			for (int i=0;i<=pos;i++)
				printf("%c",s[i]);
		}
	}
	return 0;
}