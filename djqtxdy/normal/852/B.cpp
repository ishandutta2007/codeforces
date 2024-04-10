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
const int Maxn=1e6+5;
const long long mod=1e9+7;
int st[Maxn],End[Maxn],mid[Maxn];
int n,l,m;
struct matrix{
	int x,y;
	long long mat[105][105];
	matrix(int a,int b){
		x=a,y=b;
		for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				mat[i][j]=0LL;
			}
		}
	}
	void clear(){
		for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				mat[i][j]=0LL;
			}
		}
	}
	void _debug(){
		for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				printf("%I64d ",mat[i][j]);
			}
			printf("\n");
		}
		cout<<"end"<<endl;
	}
	void I(){
		for (int i=0;i<m;i++) mat[i][i]=1;
	}
};
matrix mult(matrix a,matrix b){
	matrix c(a.x,b.y);
	for (int i=0;i<a.x;i++){
		for (int j=0;j<b.y;j++){
			for (int k=0;k<a.y;k++){
				c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
				c.mat[i][j]%=mod;
			}
		}
	}
	return c;
}
matrix qp(matrix x,int p){
	if (p==1){
		return x;
	}
	if (p==0){
		matrix tmp(m,m);
		tmp.I();
		return tmp;
	}
	if (p%2==0){
		matrix y=qp(x,p/2);
		return mult(y,y);
	}
	else{
		matrix y=qp(x,p/2);
		return mult(y,mult(y,x));
	}
}
int cnt[105],cnt2[105];
int main(){
	scanf("%d %d %d",&n,&l,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&st[i]);
	}
	for (int i=0;i<n;i++){
		scanf("%d",&mid[i]);
		cnt[mid[i]]++;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&End[i]);
		cnt2[(mid[i]+End[i])%m]++;
	}
	//cout<<cnt2[5]<<endl;
	matrix ini(m,1);
	for (int i=0;i<n;i++){
		ini.mat[st[i]][0]++;
	}
	//ini._debug();
	matrix trans(m,m);
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			trans.mat[(i+j)%m][i]+=cnt[j];
		}
	}
	matrix tmpp(m,m);
	
	tmpp=qp(trans,l-2);
	
	//tmpp._debug(); 
	ini=mult(tmpp,ini);
	//ini._debug();
	trans.clear();
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			trans.mat[(i+j)%m][i]+=cnt2[j];
		}
	}
	//trans._debug(); 
	
	ini=mult(trans,ini);
//	ini._debug();
	printf("%I64d\n",ini.mat[0][0]);
	return 0; 
}
/*
2 3 13
4 6
2 1
3 4
*/