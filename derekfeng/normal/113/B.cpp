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
typedef long long int64;
string t,bg,ed;
int SEED=1331;
const int MAX_N=2000+10;
int64 pow1[MAX_N];
int64 hashh[MAX_N];
int64 getHash(int l,int r){
	return hashh[r]-hashh[l]*pow1[r-l];
}
int64 calcHash(const string&s){
	int64 ret=0;
	for (int i=0;i<s.size();i++){
		ret=ret*SEED+s[i];
	}
	return ret;
}
int64 ss[MAX_N*MAX_N];
int cnt;
int main(){
	cin>>t>>bg>>ed;
	pow1[0]=1;
	for (int i=1;i<MAX_N;i++){
		pow1[i]=pow1[i-1]*SEED;
	}
	hashh[0]=0;
	for (int i=1;i<=t.size();i++){
		hashh[i]=hashh[i-1]*SEED+t[i-1];
	}
	int64 bh=calcHash(bg),eh=calcHash(ed);
	cnt=0;
	for (int i=0;i<t.size();i++){
		if (i+bg.size()<=t.size()){
			if (getHash(i,i+bg.size())==bh){
				for (int j=i;j<t.size();j++){
					if (j+ed.size()<=t.size()){
						if (getHash(j,j+ed.size())==eh){
							if (j+ed.size()>=i+bg.size()){
								ss[cnt++]=getHash(i,j+ed.size());
							}
						}
					}
				}
			}
		}
	}
	sort (ss,ss+cnt);
	cnt=unique(ss,ss+cnt)-ss;
	cout<<cnt;
	return 0;
}