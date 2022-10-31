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
//orz mqy
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
vector<int> t1,t2;
long long sum1[300005],sum2[300005];
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		int val;
		scanf("%d",&val);
		char t[15];
		scanf("%s",t);
		if (t[0]=='U'){
			t1.push_back(val);
		}
		else{
			t2.push_back(val);
		}
	}
	sort(t1.begin(),t1.end());
	sort(t2.begin(),t2.end());
	for (int i=0;i<t1.size();i++){
		if (i)sum1[i]=sum1[i-1];
		sum1[i]+=t1[i];
	}
	for (int i=0;i<t2.size();i++){
		if (i)sum2[i]=sum2[i-1];
		sum2[i]+=t2[i];
	}
	int MAX=-1;
	long long MAXc=-1;
	for (int k=0;k<=c;k++){
		a+=k;
		b+=(c-k);
		int hv=min(a,(int)t1.size())+min(b,(int)t2.size());
		long long cost=sum1[min(a,(int)t1.size())-1]+sum2[min(b,(int)t2.size())-1];
		if (hv>MAX){
			MAX=hv;
			MAXc=cost;
		}
		else if (hv==MAX && MAXc>cost){
			MAXc=cost;
		}
		a-=k;
		b-=(c-k);
	}
	printf("%d %I64d",MAX,MAXc);
	return 0;
}