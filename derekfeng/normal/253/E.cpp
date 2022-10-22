#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll;
int N,id;
int t[50010],s[50010],p[50010];
vector <int> p2,v;
vector <pair<int,int> > queries;
int page[50010];
priority_queue <pair<int,int> > q;
ll ans[50010];
void simulate(void){
	int i;
	REP(i,N) page[i]=s[i];
	ll T=0;
	int next=0;
	while (1){
		while (next<N && queries[next].first==T){
			int x=queries[next].second;
			q.push(make_pair(p[x],x)) ;
			next++;
		}
		if (q.empty()){
			if (next==N) return;
			T=queries[next].first;
			continue;
		}
		int y=q.top().second;
		ll T2=T+page[y];
		if (next<N) T2=min(T2,(ll)queries[next].first);
		page[y]-=T2-T;
		if (page[y]==0){
			q.pop();
			ans[y]=T2;
		}
		T=T2;
	}
}
int main(void){
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout); 
	int i;
	ll T;
	cin>>N;
	REP(i,N) scanf("%d%d%d",&t[i],&s[i],&p[i]);
	cin>>T;
	REP(i,N) if (p[i]==-1) id=i;
	p2.push_back(0);
	p2.push_back(1000000001);
	REP(i,N) if (p[i]!=-1)  p2.push_back(p[i]);
	sort (p2.begin(),p2.end());
	REP(i,p2.size()-1) if (p2[i+1]-p2[i]>=2) v.push_back((p2[i+1]+p2[i])/2);
	REP(i,N) queries.push_back(make_pair(t[i],i));
	sort (queries.begin(),queries.end());
	int low=0,high=v.size();
	while (high-low>1){
		int mid=(high+low)/2;
		p[id]=v[mid];
		simulate();
		if (ans[id]>=T) low=mid;else high=mid;
		if (ans[id]==T) break;
	}
	cout<<v[low]<<endl;
	REP(i,N){
		cout<<ans[i];
		if (i==N-1) cout<<endl;
		else cout<<" ";
	}
	return 0;
}