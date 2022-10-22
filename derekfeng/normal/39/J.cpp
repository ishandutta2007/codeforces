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
#define sz(x) ((int)(x).size())
typedef vector <int> vi;
struct hs{
public:
	static const unsigned HBASE=1000013;
	static unsigned HPOW[1000010];
	static void init(){
		HPOW[0]=1;
		for (int i=1;i<1000010;i++) HPOW[i]=HPOW[i-1]*HBASE;
	}
	vector <unsigned> h;
	hs(const string &s):h(sz(s)+1,0){
		for (int i=0;i<sz(s);i++)
			h[i+1]=h[i]*HBASE+s[i];
	}
	unsigned geth(int a,int b){
		return h[b]-h[a]*HPOW[b-a];
	}
};
unsigned hs::HPOW[1000010];
int main(){
	hs::init();
	string a,b;
	cin>>a>>b;
	hs ha(a),hb(b);
	vi v;
	for (int i=0;i<sz(a);i++)
		if (ha.geth(0,i)==hb.geth(0,i) && ha.geth(i+1,sz(a))==hb.geth(i,sz(b)))
			v.push_back(i);
	cout<<sz(v)<<endl;
	for (int i=0;i<sz(v);i++)
		cout<<v[i]+1<<" ";  
	return 0;
}