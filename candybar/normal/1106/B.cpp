#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r[maxn],c[maxn],lis[maxn],cheap;
ll totr;
bool cmp(const int &a,const int &b){
	if(c[a] == c[b]) return a < b;
	return c[a] < c[b];
}
ll calc(int t,int d){
	
//	cout << "r: ";
//	for(int i=1;i<=n;i++){
//		cout << r[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	cout << "lis: ";
//	for(int i=1;i<=n;i++){
//		cout << lis[i] << " ";
//	}
//	cout << endl;
//	system("pause");
	
	if(r[t] >= d){
		r[t] -= d;
		totr -= d;
		return (ll)c[t] * d;
	}
	ll res = 0;
	if(totr >= d){
		d -= r[t];
		res += (ll)r[t] * c[t];
		totr -= r[t];
		r[t] = 0;
		
//		cout << res << endl;
//		system("pause");
		
		while(true){
			int cur = lis[cheap];
			if(r[cur] >= d){
				r[cur] -= d;
				res += (ll)c[cur] * d;
				totr -= d;
				break;
			}
			d -= r[cur];
			res += (ll)c[cur] * r[cur];
			totr -= r[cur];
			r[cur] = 0;
			
//			cout << res << endl;
//			system("pause");
			
			cheap++;
		}
		
//		cout << res << endl;
//		system("pause");
		
		return res;
	}
	memset(r,0,sizeof(r));
	totr = 0;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		totr += r[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		lis[i] = i;
	}
	sort(lis + 1,lis + n + 1,cmp);
	cheap = 1;
	for(int i=1;i<=m;i++){
		int t,d;
		scanf("%d%d",&t,&d);
		printf("%I64d\n",calc(t,d));
	}
	return 0;
}