//  228

#include<iostream>
#include<stdio.h>
using namespace std;
#include <set>
#include<vector>
#include<algorithm>
#define ll long long
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
#include<stack>
#include<time.h>
#include<map>
//#include<bitsdc++.h>
//srand((unsigned)time(NULL));22

const int maxn = 1e5 +7;
const ll mod = 1e9+7;
const ll INF=1e17;
const int inf=1e9;
const ll maxx=1e6+7;


ll a,b,x,y;

int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	ll g=__gcd(x,y);
	x/=g;
	y/=g;
	ll ans1=a/x;
	ll ans2=b/y;
	ll max1=min(ans1,ans2);
	printf("%lld %lld\n",max1*x,max1*y);
}