//MADE IN KrK
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
typedef pair<int,int> ii;
const int Maxm=1000005;
bool prime[Maxm];
int pr[Maxm],prlen;
char str[Maxm];
int slen;
int pw10[Maxm];
int sum[Maxm];
int M;
set<ii>S;
bool Prime(int x){
	if (x<Maxm) return prime[x];
	for (int i=0;i<prlen && pr[i]*pr[i]<=x;i++)
		if (x%pr[i]==0) return false;
	return true;
}
int sRand(){return rand()%15;}
ll Random(){return ll(sRand())<<30ll | ll(sRand())<<15ll | ll(sRand());}
int Random(int l,int r){return Random()%(r-l+1)+l;}
int Get(int l,int r){
	return (sum[r]-ll(pw10[r-l+1])*sum[l-1]%M+M)%M; 
}
void randPrime(){
	M=Random(10000000,100000000);
	while (!Prime(M)) M++;
	pw10[0]=1;
	for (int i=1;i<=slen;i++){
		pw10[i]=ll(pw10[i-1])*10%M;
		sum[i]=(10ll*ll(sum[i-1])+int(str[i]-'0'))%M;
	}
}
bool Check(int a,int b,int c){
	if (a>1 && str[1]=='0') return false;
	if (b>1 && str[a+1]=='0') return false;
	if (c>1 && str[a+b+1]=='0') return false;
	return (Get(1,a)+Get(a+1,a+b))%M==Get(a+b+1,a+b+c);
}
int main(){
	fill(prime+2,prime+Maxm,true);
	for (int i=2;i<Maxm;i++) if (prime[i]){
		pr[prlen++]=i;
		for (int j=i+i;j<Maxm;j+=i) prime[j]=false;
	}
	scanf("%s",str+1);
	slen=strlen(str+1);
	randPrime();
	for (int b=0;2*b<slen;b++){
		int a=slen-2*b;
		if (a<=b){
			if (Check(a,b,b)) S.insert(ii(a,b));
			if (Check(b,a,b)) S.insert(ii(b,a));
		}
		a--;
		if (0<a && a<=b){
			if (Check(a,b,b+1)) S.insert(ii(a,b));
			if (Check(b,a,b+1)) S.insert(ii(b,a));
		}
	}
	for (int i=0;i<5;i++){
		randPrime();
		for (set<ii>::iterator it=S.begin();it!=S.end();)
			if (!Check(it->first,it->second,slen-it->first-it->second))
				S.erase(it++);
			else it++;
	}
	int a=S.begin()->first,b=S.begin()->second;
	for (int i=1;i<=a;i++)
		printf("%c",str[i]);
	printf("+");
	for (int i=1;i<=b;i++)
		printf("%c",str[a+i]);
	printf("=");
	for (int i=1;i<=slen-a-b;i++)
		printf("%c",str[a+b+i]);
}