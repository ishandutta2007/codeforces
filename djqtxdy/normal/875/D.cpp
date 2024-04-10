//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
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
#include <assert.h>
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
const int Maxn=200005;
int t1[Maxn][20],t2[Maxn][20];
int a[Maxn];
int n;
void build(){
	for (int i=1;i<=n;i++){
		t1[i][0]=a[i],t2[i][0]=a[i];
	} 
	for (int k=1;k<20;k++){
		for (int i=1;i<=n;i++){
			if (i+(1<<(k-1))>n){
				t1[i][k]=t1[i][k-1];
				t2[i][k]=t2[i][k-1];
			}
			else{
				t1[i][k]=max(t1[i][k-1],t1[i+(1<<(k-1))][k-1]);
				t2[i][k]=t2[i][k-1]|t2[i+(1<<(k-1))][k-1];
			}
		}
	}
}
int lft(int pos,int val){
	pos--;
	for (int i=19;i>=0;i--){
		if (pos<1) {
			return 1;
		}
		if (pos>=(1<<i) && t1[pos-(1<<i)+1][i]<val){
			pos-=(1<<i);
		}
		//cout<<'p'<<pos<<endl;
	}
	return pos+1;
}
int rgt(int pos,int val){
	pos++;
	for (int i=19;i>=0;i--){
		if (pos>n){
			return n;
		} 
		if (t1[pos][i]<=val){
			pos+=(1<<i);
		}
		//cout<<pos<<endl;
	}
	return pos-1;
}
int llft(int pos,int val){
	pos--;
	for (int i=19;i>=0;i--){
		if (pos<1) {
			return 1;
		}
		if (pos>=(1<<i) && (t2[pos-(1<<i)+1][i]|val)<=val){
			pos-=(1<<i);
		}
	}
	return pos+1;
}
int rrgt(int pos,int val){
	pos++;
	for (int i=19;i>=0;i--){
		if (pos>n){
			return n;
		}
		if ((t2[pos][i]|val)<=val){
			pos+=(1<<i);
		}
		//cout<<pos<<endl;
	}
	return pos-1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	//	vv[a[i]].pb(i);
	}
	build();
//	cout<<lft(5,a[5])<<' '<<rgt(1,a[1])<<endl;
	//return 0;
	//cout<<t1[1][2]<<endl;
//	cout<<lft(5,a[5]);
	//return 0;
//	cout<<cnt<<endl;
	//cout<<q2(1,1,n,2,3)<<' '<<rrgt(2,a[2])<<endl;
	//return 0;
	long long ans=0;
	for (int i=1;i<=n;i++){
		int l1=lft(i,a[i]),r1=rgt(i,a[i]),l2=llft(i,a[i]),r2=rrgt(i,a[i]);
		//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl; 
		l2--;
		r2++;
		if (l2<l1 && r2>r1) continue;
		if (l2<l1) l2=l1-1;
		if (r2>r1) r2=r1+1;
		ans+=1ll*(i-l1+1)*(r1-i+1);
		ans-=1ll*(i-l2)*(r2-i);
		
	}
	printf("%I64d\n",ans);
	return 0;
}
/*
22
3 2 1 2 3 4 5 3 2 5 5 3 22 1 2  4 3 2 1 2 5 3
*/