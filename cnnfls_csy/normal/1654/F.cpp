#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod1=998244353,mod2=1004535809,mod3=1092515507;
const int e1=31,e2=131,e3=1000003;
int pw1[262147],pw2[262147],pw3[262147],rnd[262147];
int hsh1[10000005],hsh2[10000005],hsh3[10000005],lc[10000005],rc[10000005],cnt;
vector<int> v[10000005];
int n,m,i,j;
string st;
bool cmp(int x,int y,int len)
{
	if(len==1){
		return hsh1[x]<hsh1[y];
	}
	if(hsh1[lc[x]]==hsh1[lc[y]]&&hsh2[lc[x]]==hsh2[lc[y]]&&hsh3[lc[x]]==hsh3[lc[y]]){
		return cmp(rc[x],rc[y],len/2);
	}
	else{
		return cmp(lc[x],lc[y],len/2);
	}
}
void pushup(int x,int len)
{
	hsh1[x]=(1ll*hsh1[lc[x]]*pw1[len/2]+hsh1[rc[x]])%mod1;
	hsh2[x]=(1ll*hsh2[lc[x]]*pw2[len/2]+hsh2[rc[x]])%mod2;
	hsh3[x]=(1ll*hsh3[lc[x]]*pw3[len/2]+hsh3[rc[x]])%mod3;
}
int res;
void dfs2(int x,int l,int r)
{
	if(l==r){
		putchar(hsh1[x]);
		return;
	}
	int mid=(l+r)/2;
	dfs2(lc[x],l,mid);
	dfs2(rc[x],mid+1,r);
}
vector<int> build(int l,int r)
{
	if(l==r){
		int x=++cnt;
		hsh1[x]=hsh2[x]=hsh3[x]=st[l];
		return (vector<int>){x};
	}
	int mid=(l+r)/2,i;
	vector<int> lv=build(l,mid);
	vector<int> rv=build(mid+1,r);
	vector<int> res;
	fz0k(i,lv.size()){
		cnt++;lc[cnt]=lv[i];rc[cnt]=rv[i];pushup(cnt,r-l+1);
		res.push_back(cnt);
		cnt++;lc[cnt]=rv[i];rc[cnt]=lv[i];pushup(cnt,r-l+1);
		res.push_back(cnt);
	}
/*	ff(res,it){
		dfs2(*it,l,r);cerr<<endl;
	}*/
	return res;
}
int main()
{
	srand(time(NULL));
	pw1[0]=pw2[0]=pw3[0]=1;
	fz1(i,262145){
		pw1[i]=1ll*pw1[i-1]*e1%mod1;
		pw2[i]=1ll*pw2[i-1]*e2%mod1;
		pw3[i]=1ll*pw3[i-1]*e3%mod1;
	}
	cin>>n>>st;
	vector<int> tmp=build(0,st.size()-1);
	int ans=tmp[0];
	ff(tmp,it) if(cmp(*it,ans,st.size())) ans=*it; 
	dfs2(ans,0,st.size()-1);
	return 0;
}