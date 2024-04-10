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
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
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
const int Maxn=1005;
int a[Maxn],b[Maxn];
int use[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	memset(use,0,sizeof(use));
	int l1=0,r1=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (use[a[i]]){
			l1=use[a[i]],r1=i;
		}
		else use[a[i]]=i;
	}
	int l2=0,r2=0;
	memset(use,0,sizeof(use));
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if (use[b[i]]){
			l2=use[b[i]],r2=i;
		}
		else use[b[i]]=i;
	}
	int c;
	for (int i=1;i<=n;i++){
		if (!use[i]) c=i;
	}
	if (a[l2]==c){
		b[l2]=c;
	}
	else if (a[r2]==c){
		b[r2]=c;
	}
	else if (l1==l2 && r1==r2){
		b[r2]=c;
	}
	else if (l1==l2 && a[l1]!=b[l2]){
		b[l2]=c;
	}
	else if (r1==r2 && a[r1]!=b[r2]){
		b[r2]=c;
	}
	else if (l1==r2 && a[l1]!=b[r2]){
		b[r2]=c;
	}
	else if (r1==l2 && a[r1]!=b[l2]){
		b[l2]=c;
	}
	for (int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}