#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
priority_queue<LL,vector<LL>,greater<LL> >pq;
int n;
LL sum =0;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int val;
		scanf ("%d",&val);
		pq.push(val);
	}
	if (n&1);else pq.push(0);
	while (pq.size()>1){
		LL temp = pq.top();pq.pop();
		temp+=pq.top();pq.pop();
		temp+=pq.top();pq.pop();
		sum+=temp;
		pq.push(temp);
	}
	cout<<sum<<endl;
	return 0;
}