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
const int Maxn=300005;
int a[Maxn];
vector<int> ans;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int i;
	int mx=0;
	for (i=0;i<n;){
		int l=i,r=i;
		while (l>=0 && a[l]%a[i]==0){
			l--;
		}
		l++;
		while (r<n && a[r]%a[i]==0){
			r++;
		}
		r--;
		//cout<<i<<' '<<l<<' '<<r<<endl;
		i=r+1;
		if (r-l+1>mx){
			mx=r-l+1;
			ans.clear();
			ans.push_back(l);
		}
		else if (r-l+1==mx){
			ans.push_back(l);
		}
	}
	printf("%d %d\n",(int)ans.size(),mx-1);
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]+1);
	} 
	printf("\n");
	return 0;
}