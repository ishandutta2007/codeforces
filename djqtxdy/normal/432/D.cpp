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
const int Maxn=100005;
char c[Maxn];
int z[Maxn];
int n;
int s[Maxn],ss[Maxn];
int main(){
	scanf("%s",c);
	n=strlen(c);
	int l=-1,r=-1;
	for (int i=1;i<n;i++){
		if (i>r){
			int nr=-1;
			for (int j=i;j<n;j++){
				if (c[j]==c[j-i]) nr=j;
				else break;
			}
			if (nr!=-1){
				l=i,r=nr;
			}
			z[i]=nr-i+1;
			z[i]=max(z[i],0);
		}
		else{
			int _l=0,_r=r-l,_i=i-l;
			if (z[_i]+_i-1<_r){
				z[i]=z[_i];
			}
			else{
				int nr=r;
				for (int j=r+1;j<n;j++){
					if (c[j]==c[j-i]) nr=j; else break;
				}
				z[i]=nr-i+1;
				r=nr;
				l=i;
			}
		}
		//cout<<z[i]<<endl;
	}
	for (int i=1;i<n;i++){
		s[z[i]]++;
	}
	for (int i=n-1;i>=1;i--){
		ss[i]=ss[i+1]+s[i];
	}
	vector<pair<int,int> > ans;
	for (int i=1;i<n;i++){
		if (i+z[i]-1==n-1){
			ans.push_back(mp(z[i],ss[z[i]]));
		}
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size()+1);
	for (int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second+1);
	} 
	printf("%d %d\n",n,1);
	return 0;
}