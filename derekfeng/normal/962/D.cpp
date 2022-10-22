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
#define se second
#define fi first
typedef long long ll;
typedef pair<ll,ll> pll;
ll n;
priority_queue <pll,vector <pll>,greater <pll> > q,st; 
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		ll x;
		cin>>x;
		q.push(pll(x,i));
	}
	while (!q.empty()){
		if (int(q.size())==1){
			st.push(pll(q.top().se,q.top().fi));
			q.pop();
			continue;
		}
		while (q.size()>=2){
			pll x1=q.top();
			q.pop();
			pll x2=q.top();
			q.pop();
			if (x1.fi==x2.fi){
				q.push(pll(x1.fi+x2.fi,x2.se));  
				break;
			}
			else{
				q.push(pll(x2.fi,x2.se)); 
				st.push(pll(x1.se,x1.fi));
			}
		}
	}
	cout<<st.size()<<endl;
	while (!st.empty()){
		cout<<st.top().se<<" ";
		st.pop(); 
	}
}