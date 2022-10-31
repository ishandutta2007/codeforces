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
vector<pair<int,int> > now;
int n,x,y;
int a[1005];
void Out(int a,int b){
	printf("! %d %d\n",a,b);
	fflush(stdout);
}
int tmm=0;
int ask(vector<pair<int,int> > &q){
	tmm++;
	printf("? ");
	vector<int> tmp;
	for (int i=0;i<q.size();i++){
		for (int j=q[i].first;j<=q[i].second;j++) tmp.pb(j);
	}
	printf("%d ",tmp.size());
	for (int i=0;i<tmp.size();i++){
		printf("%d ",tmp[i]);
	}
	printf("\n");
	fflush(stdout);
	int ans=0;
	//for (int i=0;i<tmp.size();i++) ans^=a[tmp[i]];
	scanf("%d",&ans);
	return ans;
}
int getans(int lo,int hi){
	if (lo==hi) return lo;
	int mid=(lo+hi)>>1;
	vector<pii > tmpp;
	tmpp.pb(mp(lo,mid));
	int mask=ask(tmpp);
	if ((mask==y) || (mask==(x^y))){
		return getans(lo,mid);
	}
	else{
		return getans(mid+1,hi); 
	}
}
int main(){
	srand(20160116);
	scanf("%d %d %d",&n,&x,&y);
	for (int i=1;i<=n;i++) a[i]=x;
	a[432]=y;
	a[516]=y;
	if (n==2){
		Out(1,2);
		return 0;
	}
	now.push_back(mp(1,n));
	vector<pair<int,int> > dl,dr;
	while (1){
		vector<pair<int,int> > l,r;
		for (int i=0;i<now.size();i++){
			int lo=now[i].first,hi=now[i].second;
			if (lo==hi) continue;
			int mid=(lo+hi)>>1;
			l.push_back(mp(lo,mid));
			r.push_back(mp(mid+1,hi));
		}
		int mask=ask(l);
		//cout<<y<<' '<<(x^y)<<endl;
		if ((mask==y) || (mask==(x^y))){
			//cout<<'G'<<endl;
			dl=l;
			dr=r;
			break;
		}
		now.clear();
		for (int i=0;i<l.size();i++) now.push_back(l[i]);
		for (int i=0;i<r.size();i++) now.push_back(r[i]);
	}
	int lf=0,rg=now.size();
	while (lf<rg-1){
		int mid=(lf+rg)>>1;
		dl.clear();
		dr.clear();
		for (int i=0;i<mid;i++){
			int lo=now[i].first,hi=now[i].second;
			if (lo>=hi) continue;
			int mm=(lo+hi)>>1;
			mm+=2;
			mm-=(rand()%5);
			if (mm<lo) mm=lo;
			if (mm>=hi) mm=hi-1;
			dl.push_back(mp(lo,mm));
			dr.push_back(mp(mm+1,hi));
		}
		for (int i=mid;i<now.size();i++){
			dl.push_back(now[i]);
		} 
		int mask=ask(dl);
		if ((mask==y) || (mask==(x^y))){
			rg=mid;
		}
		else{
			lf=mid;
		}
	}
	int low=now[lf].first,high=now[lf].second;
	int mmm=(low+high)>>1;
	int ans1=getans(low,mmm),ans2=getans(mmm+1,high);
	Out(ans1,ans2);
	//cout<<tmm<<endl;
	return 0;
}