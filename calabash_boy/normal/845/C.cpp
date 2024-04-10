#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+100;
int l[MAX],r[MAX];
int rk[MAX];
int n;
priority_queue<int,vector<int>,greater<int> >pq;
bool cmp(int x,int y){
	return l[x]<l[y];
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",l+i,r+i);
		rk[i] =i;
	}
	sort(rk,rk+n,cmp);
	for (int i=0;i<n;i++){
		int ll = l[rk[i]];
		int rr = r[rk[i]];
		while (!pq.empty()&&pq.top()<ll)pq.pop();
		pq.push(rr);
		if (pq.size()>2){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}