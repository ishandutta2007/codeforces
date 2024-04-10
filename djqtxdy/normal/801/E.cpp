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
#define int64 long long
int64 Extend_Euclid(int64 a, int64 b, int64&x, int64& y)    
{   
    if(b==0)    
    {    
        x=1,y=0;    
        return a;    
    }    
    int64 d = Extend_Euclid(b,a%b,x,y);    
    int64 t = x;    
    x = y;    
    y = t - a/b*y;    
    return d;    
}       
int64 inv(int64 a, int64 n)    
{    
    int64 x,y;    
    int64 t = Extend_Euclid(a,n,x,y);    
    if(t != 1)    
        return -1;    
    return (x%n+n)%n;    
} 
const int Maxn=200005;
const int Maxc=900;
bool f[Maxc][Maxn];
vector<long long> ans[Maxn];
int to[Maxn];
int siz[Maxn];
int fir[Maxn];
int cnt; 
bool prime[Maxn];
bool vis[Maxn];
vector<int> fac;
void Add(int v1,int v2){
	if (to[v1]==-1) to[v1]=cnt++,siz[cnt-1]=v1;
	f[to[v1]][v2]=true;
}
int org;
void solve(long long st,long long val,bool fuck){
	//if (to[val]!=-1 && fir[to[val]]==-1) return;
	if (vis[val]) return;
	vis[val]=true;
	long long stt=st;
	if (val==1){
		if (to[org]==-1 || !f[to[org]][0]){
			ans[val].push_back(0);//cout<<val<<endl;
		}
		return;
	}
	if (prime[val]){
		
		//cout<<val<<endl;
		
		for (int i=1;i<val;i++){
			if (to[val]!=-1 && f[to[val]][i] || (fuck && stt==i)) continue;
			long long ff=inv(st,val);
			//if (ff==-1) cout<<st<<val<<endl;
			ff*=i;
			
			ff%=val;
			
			ans[val].push_back(ff);
			st*=ff;
			st%=val; 
		}
		if (to[org]==-1 || !f[to[org]][0]){
			ans[val].push_back(0);//cout<<val<<endl;
		}
		return;
	}
	for (int i=0;i<val;i++){
		if (to[val]!=-1 && f[to[val]][i]|| (fuck && stt==i)) continue;
		if (__gcd((LL)i,val)!=1){
			continue;
		}
		long long ff=inv(st,val);
		ff*=i;
		ff%=val;
		ans[val].push_back(ff);
		st*=ff;
		st%=val; 
	}
	
	//cout<<val<<endl; 
//	for (int i=0;i<ans[val].size();i++){
	//	cout<<ans[val][i]<<' ';
	//}
	//cout<<endl;
	int maxs=-1,mi=-1;
	long long innum=-1;
	for (int i=0;i<fac.size();i++){
		if (val%fac[i]!=0) continue;
		int num=to[val/fac[i]];
		long long v=(num==-1)?1:fir[num];
		if (v==-1) continue;
		//cout<<fac[i]<<' '<<v<<endl;
		Add(val/fac[i],v);
		//f[val/fac[i]][v]=true;
		solve(v,val/fac[i],true);
		v*=(LL)fac[i];
		v%=val;
		v*=(LL)inv(st,val);
		//if (inv(st,val)==-1) cout<<"ERROR";
		v%=val;
		//cout<<fac[i]<<' '<<v<<' '<<ans[val/fac[i]].size()<<endl;
		if ((int)ans[val/fac[i]].size()>maxs){
			maxs=(int)ans[val/fac[i]].size();
			innum=v;
			mi=val/fac[i];
		}
	}
	//cout<<innum<<endl;
	if (innum==-1) return; 
	ans[val].push_back(innum);
	for (int i=0;i<ans[mi].size();i++){
		ans[val].push_back(ans[mi][i]);
	}
	return;
}
int main(){
	//cout<<inv(99999,100000);
//	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	for (int i=2;i<Maxn;i++){
		prime[i]=true;
	}
	for (int i=2;i<Maxn;i++){
		if (prime[i]){
			for (int j=i+i;j<Maxn;j+=i){
				prime[j]=false;
			}
		}
	}
	memset(to,-1,sizeof(to));
	memset(fir,-1,sizeof(fir));
	int n,m;
	scanf("%d %d",&n,&m);org=m;
	int bm=m;
	for (int i=2;i*i<=m;i++){
		if (m%i==0){
			fac.push_back(i);
			while (m%i==0){
				m/=i;
			}
		}
	}
	if (m>1) fac.push_back(m);
	m=bm;
	for (int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		int gcd=__gcd(tmp,m);
		if (tmp==0) gcd=1;
		Add(m/gcd,tmp/gcd);
	}
	
	for (int i=0;i<cnt;i++){
		for (int j=1;j<=siz[i];j++){
			if (!f[i][j%siz[i]] && __gcd(siz[i],j)==1 ){
				fir[i]=j%siz[i];
				break;
			}
		}
	}
//	cout<<fir[to[10001]]<<endl;
	solve(1,m,false);
	/*
	for (int i=0;i<cnt;i++){
		if (vis[siz[i]]){
			cout<<"ANS:"<<siz[i]<<endl;
			for (int j=0;j<ans[siz[i]].size();j++){
				 cout<<ans[siz[i]][j]<<' ';
			}
			cout<<endl;
		}
	}*/
	printf("%d\n",ans[m].size());
	for (int i=0;i<ans[m].size();i++){
		printf("%d ",ans[m][i]);
	}
	printf("\n");
}