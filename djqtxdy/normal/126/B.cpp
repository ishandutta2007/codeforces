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
const int Maxn=1000005;
char c[Maxn];
int z[Maxn];
int main(){
	scanf("%s",c);
	int n=strlen(c);
	int l=-1,r=-1;
	for (int i=1;i<n;i++){
		if (i>r){
			for (int j=i;j<n;j++){
				if (c[j]==c[j-i])z[i]++;
				else break;
			}
			if (z[i]==0) continue;
			l=i,r=z[i]+l-1;
			//cout<<'f'<<l<<' '<<r<<' '<<z[i]<<endl;
		}
		else{
			int _l=0,_r=r-l,_i=i-l;
			if (z[_i]+_i-1<_r){
				z[i]=z[_i];
			}
			else{
				z[i]=r-i+1;
				for (int j=r+1;;j++){
					if (c[j]==c[j-i]){
						z[i]++;
					}
					else break;
				}
				l=i;
				r=l+z[i]-1;
			}
		}
	//	cout<<l<<' '<<r<<' ';
	//	printf("%d\n",z[i]);
	}
	int ans=0;
	int Mx=0;
	for (int i=1;i<n;i++){
		if (z[i]+i-1==n-1){
			if (Mx>=z[i])
			ans=max(ans,z[i]);
		}
		Mx=max(Mx,z[i]);
	}
	if (ans==0){
		printf("Just a legend\n");
		return 0;
	}
	for (int i=0;i<ans;i++){
		printf("%c",c[i]);
	}
	printf("\n");
	return 0;
}