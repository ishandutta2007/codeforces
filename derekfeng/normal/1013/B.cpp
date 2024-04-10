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
int n,k;
int a[100003];
int a_bit[100003];
int bit_num[18];
int pika(int a,int b) {
	int num1=a,num2=b,gow=0,i=17;
	while  (num1 && num2) {
		if (num1-bit_num[i]>=0 && num2-bit_num[i]>=0) gow+=bit_num[i];
		if (num1-bit_num[i]>=0) num1-=bit_num[i];
		if (num2-bit_num[i]>=0) num2-=bit_num[i];
		i--;
	}
	return gow;
}
int vis1[100003];
int vis2[100003];
int main() {
	bit_num[0]=1;
	for (int i=1; i<18; i++) {
		bit_num[i]=bit_num[i-1]*2;
	}
	cin>>n>>k;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		a_bit[i]=pika(a[i],k);
		vis1[a[i]]++;
		if (vis1[a[i]]>1) {
			cout<<0;
			return 0;
		}
	}
	for (int i=0; i<n; i++)
		if (a_bit[i]!=a[i])
			if (vis1[a_bit[i]]>=1) {
			cout<<1;
			return 0;
			}
	for (int i=0; i<n; i++) {
		vis2[a_bit[i]]++;
		if (vis2[a_bit[i]]>1) {
			cout<<2;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}