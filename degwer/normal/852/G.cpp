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
int n,m;
map<string,int>S;
int main(){
	cin>>n>>m;
	rep(i,n){
		string a;cin>>a;S[a]++;
	}
	rep(i,m){
		string b;cin>>b;set<string>Q;
		int cnt=0,T=1;
		rep(j,b.size()) cnt+=(b[j]=='?');
		rep(j,cnt) T*=6; int ret=0;
		rep(j,T){
			int x[3],J=j,nxt=0;
			rep(k,cnt){
				x[k]=J%6;J/=6;
			}
			string SS=""; 
			rep(k,b.size()){
				if(b[k]!='?')SS.pb(b[k]);
				else{
					if(x[nxt]<5) SS.pb('a'+x[nxt]);
					nxt++;
				}
			}
			if(S.find(SS)!=S.end())Q.insert(SS);
		}int ans=0;
		for(set<string>::iterator it=Q.begin();it!=Q.end();++it)ans+=S[*it];
		cout<<ans<<endl;
	}
}