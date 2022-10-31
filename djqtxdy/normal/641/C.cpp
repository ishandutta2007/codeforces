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
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int ans[2000000];
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	bool f=false;
	int so=1,se=2;
	for (int i=0;i<q;i++){
		int tp;
		tp=read();
		if (tp==1){
			//cout<<so<<se<<endl;
			int val;
			val=read();
			if (val<0) val+=n;
			val%=n;
			val=n-val;
		//	cout<<val<<' '<<f<<endl;
			if (val%2==1){
				if (f) se+=2;
				else so+=2;
				f=!f;
			}
			so+=2*(val/2);
			se+=2*(val/2);
			if (so>n) so-=n;
			if (se>n) se-=n;
			if (so<1) so+=n;
			if (se<1) se+=n;
		//	cout<<so<<se<<endl;
		}
		else{
			f=!f;
		}
	}
	for (int i=0;i<n/2;i++){
		ans[i*2]=se+i*2;
		if (ans[i*2]>n) ans[i*2]-=n;
		ans[i*2+1]=so+i*2;
		if (ans[i*2+1]>n) ans[i*2+1]-=n;
		if (!f) swap(ans[i*2],ans[i*2+1]);
	}
	for (int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}