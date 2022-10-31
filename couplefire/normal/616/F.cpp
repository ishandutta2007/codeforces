#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int N = 1e5+5;
const int M = 5e5+5;
const int L = N+M;
const int V = L*2;
 
#define link ololink
int len[V], to[V][27], link[V], pos[V];
ll f[V];
int d, l;
 
int code(int c){
	if(c=='#') return 26;
	return c-'a';
}
 
char s[L];
int sn;
int g[L];
void addc(int c, int xxx){
	s[sn++] = c;
	c = code(c);
	int x = d++;
	f[x] = xxx;
	len[x] = len[l]+1;
	pos[x] = sn-1;
	for(;l!=-1 && !to[l][c]; l=link[l]) to[l][c] = x;
	if(l!=-1){
		int p = to[l][c];
		if(len[p]==len[l]+1) link[x] = p; else{
			int q = d++;
			len[q] = len[l]+1;
			link[q] = link[p];
			pos[q] = pos[p];
			memcpy(to[q], to[p], sizeof(to[q]));
			for(;l!=-1 && to[l][c]==p; l=link[l]) to[l][c]=q;
			link[x] = link[p] = q;
		}
	}
	l=x;
}
 
string t[N];
int a[N];
vector<int> v[L];
 
int main(){
	//freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
	
	d = 0;
	l = d++;
	link[l] = -1;
	
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%s",&s);
		t[i] = s;
	}
	
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	
	for(int i=0;i<n;++i){
		addc('#', 0);
		for(char c : t[i]) addc(c, a[i]);
	}
	
	g[0] = 0;
	for(int i=1;i<sn;++i) if(s[i]=='#') g[i]=i; else g[i]=g[i-1];
	
	//cout<<s<<endl; for(int i=0;i<sn;++i) cout<<g[i]<<' '; cout<<endl;
	
	
	for(int i=0;i<d;++i) v[len[i]].push_back(i);
	
	
	ll ans = 0;
	for(int h=sn;h;--h)
	for(int i : v[h]){
		int j = link[i];
		f[j]+=f[i];
		
		int lng = len[i];
		if(pos[i]-lng+1<=g[pos[i]]) lng = pos[i]-g[pos[i]];
		
		if(lng>len[j]){
			ll res = f[i] * lng;
			ans = max(ans, res);
			//cout<<"?"<<f[i]<<' '<<lng<<' '<<pos[i]<<endl;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}