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
const int Maxn=1e5;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
map<int,int> g;
int cr=0;
int f(int x){
	
	if (g.count(x)) return g[x];
	cr++;
	vector<int> v;
	for (int i=0;i<31;i++){
		if ((1<<(i))>x){
			break;
		}
		int y=x>>(i+1),z=(x)&((1<<i)-1);
		y=y|z;
		v.push_back(f(y));
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	//cout<<v.size()<<endl;
	if (v[0]!=0){
		return g[x]=0;
	}
	for (int i=1;i<v.size();i++){
		if (v[i]!=v[i-1]+1){
			return g[x]=v[i-1]+1;
		}
	}
	return g[x]=v.back()+1;
}
void ff(int tmp){
	string ans;
	while (tmp){
		ans+=(char)(tmp%2+'0');
		tmp/=2;
	} 
	if (ans.size()==0) ans="0";
	reverse(ans.begin(),ans.end());
	cout<<ans<<' ';
}
map<int,int> pr;
bool isp[Maxn*2];
void _init(){
	memset(isp,true,sizeof(isp));
	for (int i=2;i<Maxn*2;i++){
		if(isp[i]){
			for (int j=i+i;j<2*Maxn;j+=i){
				isp[j]=false;
			} 
		}
	}
}
void solve(int x){
	int cnt=0;
	for (int i=2;i*i<=x;i++){
		if (isp[i] && x%i==0){
			cnt=0;
			while (x%i==0){
				x/=i;
				cnt++;
			}
			cnt--;
			pr[i]|=(1<<cnt);
		}
	}
	if (x!=1){
		pr[x]|=1;
	}
}
int main(){
	_init();
	g[0]=0;
	int tot=0;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		solve(x);
	}
	int t=0;
	for (auto i:pr){
		t^=f(i.second);
	}
	if (t!=0){
		printf("Mojtaba\n");
	}
	else{
		printf("Arpa\n");
	}
	return 0;
}