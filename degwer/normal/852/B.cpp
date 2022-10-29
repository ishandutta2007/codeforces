#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,L;
int a[1000005],b[1000005],c[1000005];
ll cnt[1005],cnt2[1005];
ll x[1005][22],val[1005][22];
int main(){
    srand((unsigned)time(NULL));
	cin>>n>>m>>L;
	repn(i,n){
		scanf("%d",&a[i]);
		cnt[a[i]%L]++; a[i]%=L;
	}
	repn(i,n){
	    scanf("%d",&b[i]); b[i]%=L;
	}
	repn(i,n){
		scanf("%d",&c[i]); c[i]%=L;
		x[b[i]%L][0]++;
		cnt2[(b[i]+c[i])%L]++;
	}
	//m-2
	rep(i,21){
		rep(j,L){
			rep(k,L){
				x[(j+k)%L][i+1] = (x[(j+k)%L][i+1]+x[j][i]*x[k][i]%mod)%mod;
			}
		}
	}
	int pre = 0; val[0][0] = 1;
	rep(i,22){
		if(!(( (m-2) >> i)&1)) continue;
		rep(j,L){
			rep(k,L){
				val[(j+k)%L][pre+1] = (val[(j+k)%L][pre+1]+val[j][pre]*x[k][i]%mod)%mod;
			}
		}
		pre++;
	}
	ll ans=0;
	rep(i,L)rep(j,L){
		ans=(ans+1LL*cnt[i]*cnt2[j]%mod*val[(L+L-i-j)%L][pre]%mod)%mod;
	}
	cout<<ans<<endl;
}