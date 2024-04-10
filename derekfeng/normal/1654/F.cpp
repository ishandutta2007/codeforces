#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const ll inf=1e9;
int n,N;
char s[262200];
int f[262200];
vector<pair<ll,pii> >v;
int main(){
	scanf("%d%s",&n,s),N=(1<<n);
	for(int i=0;i<N;i++)f[i]=s[i]-'a';
	for(int t=2;t<=N;t<<=1){
		v.clear();
		for(int l=0,r=t-1;r<N;l+=t,r+=t){
			for(int j=0;j<(t>>1);j++){
				int m=(l+r)/2+1;
				ll state;
				state=inf*f[l+j]+f[m+j];
				v.push_back({state,{l,j}});
				state=inf*f[m+j]+f[l+j];
				v.push_back({state,{l,j|(t>>1)}});
			}
		}
		sort(v.begin(),v.end());
		int cnt=0;
		for(int i=0;i<v.size();i++){
			if(i==0||v[i].fi!=v[i-1].fi)++cnt;
			f[v[i].se.fi+v[i].se.se]=cnt;
		}
	}
	int x=v[0].se.se;
	for(int i=0;i<N;i++)putchar(s[i^x]);
}