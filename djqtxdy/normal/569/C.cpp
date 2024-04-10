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
// prime : 4 palind: 9
// pi(n)<= p/q rub(n)
// q* pi (n)<= p* rub(n)
const int Maxm=10000000;
bool isp[Maxm],ispa[Maxm];
int pp[10];
bool f(int x){
	int w=0;
	int tmp=x;
	while (tmp){
		w++;
		tmp/=10;
	}
	int y=0;
	tmp=x;
	for (int i=0;i<w;i++){
		y+=pp[w-i-1]*(tmp%10);
		tmp/=10;
	}
	return x==y;
}
void _init(){
	memset(isp,true,sizeof(isp));
	isp[1]=false;
	for (int i=2;i<Maxm;i++){
		if (isp[i]){
			for (int j=i+i;j<Maxm;j+=i){
				isp[j]=false;
			}
		}
	}
	for (int i=1;i<Maxm;i++){
		ispa[i]=f(i);
	}
}
int main(){
	pp[0]=1;
	for (int i=1;i<=9;i++) pp[i]=pp[i-1]*10;
	int p,q;
	scanf("%d %d",&p,&q);
	_init();
	int s1=0,s2=0;
	int mx=0;
	for (int i=1;i<Maxm;i++){
		s1+=isp[i];
		s2+=ispa[i];
		if ((LL)q*(LL)s1<=(LL)p*(LL)s2) mx=i;
	}
	printf("%d\n",mx);
	return 0;
}