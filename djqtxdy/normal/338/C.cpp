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
const int Maxn=10;
const int Maxm=1e6+5;
LL a[Maxn];
int res;
vector<vector<pair<LL,bool> > > now;
vector<int> p;
bool isp[Maxm];
map<LL,int> ss;
void _init(){
	memset(isp,true,sizeof(isp));
	isp[0]=isp[1]=false;
	for (int i=2;i<Maxm;i++){
		if (isp[i]){
			p.pb(i);
			for (int j=i+i;j<Maxm;j+=i){
				isp[j]=false;
			}
		}
	}
//	cout<<p.size()<<endl;
}
int g(LL x){
	if (ss.count(x)) return ss[x];
	LL tmp=x;
	int ans=0;
	for (int i=0;i<p.size();i++){
		while (tmp%p[i]==0){
			tmp/=p[i];
			ans++;
		}
	}
	if (tmp!=1) ans++;
	return ss[x]=ans;
}
int n;
int f(){
	int ret=0;
	if (now.size()>1) ret=1;
	for (int i=0;i<now.size();i++){
		ret+=now[i].size()-1;
		for (int j=0;j<now[i].size();j++){
			int x=g(now[i][j].first);
			if (now[i][j].second && x!=1) x++;
			ret+=x;
		}
	}
	return ret;
}
void go(int lvl){
	if (lvl==n){
		/*
		cout<<"size: "<<now.size()<<endl;
		for (int i=0;i<now.size();i++){
			for (int j=0;j<now[i].size();j++){
				cout<<now[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"cost: "<<f()<<endl;*/
		res=min(res,f());
		return;
	} 
	for (int i=0;i<now.size();i++){
		vector<pair<LL,bool> > tmp=now[i];
		for (int j=0;j<now[i].size();j++){
			if (now[i][j].first%a[lvl]==0){
				if (now[i][j].first!=a[lvl]){
					now[i].push_back(mp(now[i][j].first/a[lvl],false));
				}
				now[i][j].first=a[lvl];
				now[i][j].second=true;
				go(lvl+1);
				now[i]=tmp;
			}
		}
	}
	vector<pair<LL,bool> > ept;
	ept.pb(mp(a[lvl],true));
	now.pb(ept);
	go(lvl+1);
	now.pop_back();
}
int main(){
	_init();
//	cout<<g(6)<<' '<<g(10)<<endl;
	res=1e9;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
	sort(a,a+n);
	reverse(a,a+n);
	go(0);
	printf("%d\n",res);
	return 0;
}