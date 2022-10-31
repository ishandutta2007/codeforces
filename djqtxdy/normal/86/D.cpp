#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=200005;
const int Maxm=1000005;
const int blocks=305;
long long BIT[Maxn];
int a[Maxn];
int cnt[Maxm];
int n,q;
int ql[Maxn],qr[Maxn];
vector<int> qur[Maxn];
int sum[Maxn];
long long res[Maxn];
vector<int> hav[Maxm];
void modify(int pos,long long val){
	while (pos<=n){
		BIT[pos]+=val;
		pos+=pos&-pos;
	}
}
long long query(int pos){
	long long res=0;
	while (pos>0){
		res+=BIT[pos];
		pos-=pos&-pos;
	}
	return res;
}
int main(){
	scanf("%d %d",&n,&q);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (int i=0;i<q;i++){
		scanf("%d %d",&ql[i],&qr[i]);
		ql[i]--;
		qr[i]--;
		qur[ql[i]].push_back(i);
	}
	for (int i=0;i<Maxm;i++){
		if (cnt[i]>blocks){
			for (int j=0;j<n;j++) sum[j]=0;
			for (int j=0;j<n;j++){
				if (a[j]==i){
					sum[j]=((j==0)?0:sum[j-1])+1;
					a[j]=0;
				}
				else{
					sum[j]=((j==0)?0:sum[j-1]);
				}
			}
			for (int j=0;j<q;j++){
				res[j]+=(LL)(sum[qr[j]]-(ql[j]==0?0:sum[ql[j]-1]))*(sum[qr[j]]-(ql[j]==0?0:sum[ql[j]-1]))*i;
			}
		}
	}
	for (int i=n-1;i>=0;i--){
		if (a[i]!=0){
			modify(i+1,(LL)a[i]);
			for (int j=0;j<hav[a[i]].size();j++){
				modify(hav[a[i]][j],(LL)a[i]<<1);
			}
			hav[a[i]].push_back(1+i);
			for (int j=0;j<qur[i].size();j++){
				res[qur[i][j]]+=query(qr[qur[i][j]]+1);
			}
		}
	}
	for (int i=0;i<q;i++) {
		printf("%I64d\n",res[i]);
	}
	return 0;
}