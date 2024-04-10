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
/* max (a,b)=k:
proa[k]*spb[k-1]+prob[k]*spa[k-1]+proa[k]*prob[k]
spb[k-1], spa[k-1]:: known
proa[k]=x;
prob[k]=y;
x*C1+y*C2+xy= Z1
min(a,b)=k
proa[k]*(1-spb[k])+prob[k]*(1-spa[k])+proa[k]*prob[k]
x*(1-spb[k]) + y*(1-spa[k])+xy
x*(1-spb[k-1]-y)+y*(1-spa[k-1]-x)-xy


(1). x*(1-C1)+y*(1-C2)-xy=Z2;
(2). x*C1+y*C2+xy= Z1


(1)+(2): x+y=Z1+Z2; (3)
(1)-(2): (1-2C1)x+(1-2C2)y-2xy=Z2-Z1; (4)
s=(1-2C1),t=(1-2C2)
(4): sx+ty-2xy=Z2-Z1;

sx+t(Z1+Z2-x)-2x(Z1+Z2-x)=Z2-Z1;
sx+tZ1+tZ2-tx-(2Z1+2Z2)x+2x^2=Z2-Z1;
sx-tx-(2Z1+2Z2)x+2x^2=Z2-Z1-tZ1-tZ2

(s-t)x+t(Z1+Z2)+2x^2-2x(Z1+Z2)=Z2-Z1
2x^2-((s-t)-2(Z1+Z2))x=Z2-Z1-t(Z1+Z2)

ax^2+bx+c=0
a=2;
b=(s-t-2Z1-2Z2)
c=(tZ1+tZ2-Z2+Z1)

2/3 * (1): 2/3(1-C1) x+ 2/3(1-C2) y-2xy=2/3 Z2 (6)

(6)+(3): (2/3(1-C1)+1) x+ (2/3(1-C2)+1) y=Z1+5/3Z2 (7)
(5): (2C1-1)x+(2C2-1)y=Z1-Z2
(7): (2/3(1-C1)+1) x+ (2/3(1-C2)+1) y=Z1+5/3Z2
*/
// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
double ans1[Maxn],ans2[Maxn];
double p1[Maxn],p2[Maxn];
double sum1[Maxn],sum2[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	double C1=0.0,C2=0.0;
	for (int i=1;i<=n;i++){
		scanf("%lf",&p1[i]);
		sum1[i]=sum1[i-1]+p1[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%lf",&p2[i]);
		
	}
	for (int i=n;i>=1;i--){
		sum2[i]=sum2[i+1]+p2[i];
	}
	for (int i=1;i<=n;i++){
		double Z1=sum1[i],Z2=sum2[i+1];
		double Z3=Z1-Z2+1;
		double a=-1.0,b=Z3,c=-Z1;
		//cout<<Z1<<' '<<Z2<<endl;
		double delta=max(0.0,sqrt(b*b-4.0*a*c));
		double x1=(-b+delta)/(2.0*a),x2=(-b-delta)/(2.0*a);
		ans1[i]=x1;
		if (x1!=0)ans2[i]=Z1/(double)x1;
		else ans2[i]=1.0-Z2/(double)(1-x1);
	}
	for (int i=1;i<=n;i++){
		printf("%lf ",ans1[i]-ans1[i-1]);
	}
	printf("\n");
	for (int i=1;i<=n;i++){
		printf("%lf ",ans2[i]-ans2[i-1]);
	}
	printf("\n");
	return 0;
}
/*
3
0.125 0.25 0.625
0.625 0.25 0.125
*/