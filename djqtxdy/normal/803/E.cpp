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
bool f[Maxn][Maxn*2];
char pre[Maxn][Maxn*2];
char c[Maxn];
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",c+1);
	f[0][k]=true;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=2*k;j++){
			if (c[i]=='W'){
				if (j>1) f[i][j]=f[i-1][j-1];
			}
			else if (c[i]=='L'){
				if (j<2*k-1) f[i][j]=f[i-1][j+1];
			}
			else if (c[i]=='D'){
				if (j!=0 && j!=2*k) f[i][j]=f[i-1][j];
			}
			else{
				if (j>1 && f[i-1][j-1]) f[i][j]=f[i-1][j-1],pre[i][j]='W';
				if (j<2*k-1 && f[i-1][j+1]) f[i][j]=f[i-1][j+1],pre[i][j]='L';
				if (j!=0 && j!=2*k && f[i-1][j]) f[i][j]=f[i-1][j],pre[i][j]='D';
			}
		}
	}
	if (!f[n][0] && !f[n][2*k]){
		printf("NO\n");
		return 0;
	}
	int x,y;
	if (f[n][0]){
		x=n,y=0;
	} 
	else if (f[n][2*k]){
		x=n,y=2*k;
	}
	//cout<<x<<y<<endl;
	while (x){
	//	cout<<pre[x][y]<<' '<<x<<' '<<y<<endl;
		if (c[x]=='?') c[x]=pre[x][y];
		if (c[x]=='W'){
			y--;
		}
		else if (c[x]=='L'){
			y++;
		} 
		else if (c[x]=='D'){
			y+=0;
		}
		x--;
	}
	printf("%s\n",c+1);
	return 0;
}