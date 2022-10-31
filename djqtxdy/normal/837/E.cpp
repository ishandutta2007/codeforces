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
bool isp[Maxn];
vector<int> p;
LL gcd(LL x,LL y){
	if (!y) return x;
	return gcd(y,x%y);
}
int main(){
	memset(isp,true,sizeof(isp));
	isp[1]=isp[0]=false;
	for (int i=2;i<Maxn;i++){
		if (isp[i]) p.pb(i);
		for (int j=i+i;j<Maxn;j+=i){
			isp[j]=false;
		}
	}
//	cout<<p.size()<<endl;
	long long x,y;
	scanf("%I64d %I64d",&x,&y);
	/*
	LL tx=x,ty=y;
	LL ans=0;
	while (ty){
		LL zz=gcd(tx,ty);
		ty-=zz;
		ans++;
	}cout<<ans<<endl;*/
	LL z=gcd(x,y);//cout<<z<<end
	x/=z;
	y/=z;
	//cout<<x<<y<<endl;
	LL ans=0;
	while (1){
		if (!y) break;
		vector<LL> now;
		LL tmp=x;
		for (int i=0;i<p.size();i++){
			if (tmp%(LL)p[i]==0LL){
				now.push_back((LL)p[i]);
				while (tmp%p[i]==0) tmp/=p[i];
			}
		}
		
		//cout<<tmp<<endl;
		if (tmp!=1) now.push_back(tmp);
		LL mx=0;
		for (int i=0;i<now.size();i++){
			LL pr=now[i];
			LL val=y/(LL)pr*(LL)pr;
			mx=max(mx,val);
		}
		ans+=(y-mx);
		y=mx;
		z=gcd(x,y);
		//cout<<x<<' '<<y<<endl;
		x/=z;
		y/=z;
		//cout<<x<<' '<<y<<endl;
	}
	printf("%I64d\n",ans);
	return 0;
}