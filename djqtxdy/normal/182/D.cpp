#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=100005;
char s[Maxn],t[Maxn];
const long long mul=Maxn+2;
const long long mod=1e12+7;
int main(){
	scanf("%s\n",s);

	scanf("%s",t);
	int n=strlen(s),m=strlen(t);
	int ans1=0;
	long long mogic1=0,mogic2=0;
	long long now=1;
	for (int i=0;i<n-1;i++){
		mogic1=mogic1*mul+s[i];
		mogic1%=mod;
		mogic2=mogic2+now*s[n-i-1];
		mogic2%=mod;
		now*=mul;
		now%=mod;
		if (mogic1==mogic2) ans1=i+1;
	}
//	cout<<ans1<<endl;
	int len=n-ans1;
	if (n%len!=0) len=n; 
	string k;
	for (int i=0;i<len;i++){
		k+=s[i];
	}
	string kk;
	int ans2=0;
	mogic1=0,mogic2=0;
	now=1;
	for (int i=0;i<m-1;i++){
		mogic1=mogic1*mul+t[i];
		mogic1%=mod;
		mogic2=mogic2+now*t[m-i-1];
		mogic2%=mod;
		now*=mul;
		now%=mod;
		if (mogic1==mogic2) ans2=i+1;
	}
//	cout<<ans2<<endl;
	int len2=m-ans2;
	if (m%len2!=0) len2=m; 
	for (int i=0;i<len2;i++){
		kk+=t[i];
	}
	//cout<<k<<' '<<kk<<endl;
	if (k!=kk){
		printf("0\n");
	}
	else{
		int t1=n/len,t2=m/len2;
		int res=0;
		for (int i=1;i<=min(t1,t2);i++){
			if (t1%i==0 && t2%i==0) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}