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
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
// cf IO: I64d
// atcoder IO: 
const int Maxn=1005;
char c[Maxn];
int n,p;
void a(){
	c[n-1]++;
	int k=n-1;
	while (c[k]==p+'a'){
		if (k==0){
			printf("NO\n");
			exit(0);
		}
		c[k]='a';
		c[k-1]++;
		k--;
	}
}
bool b(){
	long long sh=0,vh=0;
	long long kk=big;
	long long now=1;
	long long mod=1e12+7;
	for (int st=0;st<n;st++){
		sh=0,vh=0;
		now=1;
		for (int j=st;j<n;j++){
			sh=sh*kk+c[j];
			sh%=mod;
			vh+=c[j]*now;
			vh%=mod;
			now*=kk;
			now%=mod;
			if (j!=st && sh==vh) return false;
		}
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&p);
	char lim=p+'a';
	if (p==1){
		printf("NO\n");
		return 0;
	}
	scanf("%s",c);
	if (p==2 && n==1){
		if (c[0]=='a') printf("b\n");
		else printf("NO\n");
		return 0;
	}
	if (p==2 && n==2){
		if (c[0]=='a') printf("ba\n");
		else printf("NO\n");
		return 0;
	}
	for (int i=n-1;i>=0;i--){
		for (char ch=c[i]+1;ch<lim;ch++){
			if ((i!=0 && ch==c[i-1]) || (i>1 && ch==c[i-2])) continue;
			c[i]=ch;
			for (int j=i+1;j<n;j++){
				for (char ch='a';ch<lim;ch++){
					if (ch==c[j-1] || (j!=1 && ch==c[j-2]))continue;
					c[j]=ch;
					break;
				}
			}
			printf("%s\n",c);
			return 0;
		}
	} 
	printf("NO\n");
}