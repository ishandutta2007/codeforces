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
const int Maxn=100005;
const int Maxk=320;
int val[Maxk][Maxn];
int a[Maxn];
deque<int> buck[Maxk];
int n,q;
void _debug(){
	for (int i=0;i<Maxk;i++){
		printf("%d ",val[i][1]);
	}
	printf("\n");
}
int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		val[i/Maxk][x]++;
		buck[i/Maxk].push_back(x);
		a[i]=x;
	}
	scanf("%d",&q);
	int lastans=0;
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		int l,r,k;
		if (tp==1){
			scanf("%d %d",&l,&r);
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			if (l>r) swap(l,r);
			l--;r--;
			//cout<<"query:"<<l<<' '<<r<<endl;
			int L=l/Maxk,R=r/Maxk;
			if (L==R){
				buck[L].insert(buck[L].begin()+l%Maxk,buck[L][r%Maxk]);
				buck[L].erase(buck[L].begin()+r%Maxk+1);
			}
			else{
				buck[R].push_front(buck[R-1].back());
				val[R][buck[R-1].back()]++;
				for (int i=R-1;i>L;i--){
					val[i][buck[i-1].back()]++;
					buck[i].push_front(buck[i-1].back());
					val[i][buck[i].back()]--;
					buck[i].pop_back();
				}
				val[L][buck[L].back()]--;
				buck[L].pop_back();
				val[L][buck[R][r%Maxk+1]]++;
				buck[L].insert(buck[L].begin()+l%Maxk,buck[R][r%Maxk+1]);
				val[R][buck[R][r%Maxk+1]]--;
				buck[R].erase(buck[R].begin()+r%Maxk+1);
			}
		//	_debug();
		}
		else if (tp==2){
			scanf("%d %d %d",&l,&r,&k);
			l=(l+lastans-1)%n+1;
			r=(r+lastans-1)%n+1;
			k=(k+lastans-1)%n+1; 
			int ans=0;
			if (l>r) swap(l,r);
			l--;r--;
			int L=l/Maxk,R=r/Maxk;
			if (L==R){
				for (int i=l;i<=r;i++){
					ans+=(buck[L][i%Maxk]==k);
				}
			}
			else{
				for (int i=L+1;i<R;i++){
					ans+=val[i][k];
				}
				for (int i=l;i<(L+1)*Maxk;i++){
					ans+=(buck[L][i%Maxk]==k);
				}
				for (int i=R*Maxk;i<=r;i++){
					ans+=(buck[R][i%Maxk]==k);
				} 
			}
			printf("%d\n",ans);
			lastans=ans;
		}
	}
}