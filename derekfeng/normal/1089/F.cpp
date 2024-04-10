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
typedef long long ll;
ll n,a,b,k;
int main(){
	cin>>n;
	k=n-1;
	for (int i=2;i*i<=n;i++)
		if (n%i==0){
			a=i,b=n/i;
			if(__gcd(a,b)==1)
			while(a<k){
				if((k-a)%b==0&&a/i<b){
					puts("YES");
					cout<<2<<endl<<(k-a)/b<<" "<<i<<endl<<a/i<<" "<<b;	
					return 0;
				}
				a=a+i;
			}
		}
	puts("NO");
	return 0;
}