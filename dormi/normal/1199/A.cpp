#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,x,y;
	cin>>n>>x>>y;
	deque<pair<int,int>> q;
	int arr[n];
	bool work[n]={};
	for(int i=0;i<n;i++){
		cin>>arr[i];
		while(q.size()&&q.back().first>arr[i]){
			q.pop_back();
		}
		q.push_back({arr[i],i});
		while(q.size()&&q.front().second<i-x){
			q.pop_front();
		}
		if(q.front().second==i){
			work[i]=true;
		}
	}
	int loc=-1;
	for(int i=n-1;i>=0;i--){
		while(q.size()&&q.back().first>arr[i]){
			q.pop_back();
		}
		q.push_back({arr[i],i});
		while(q.size()&&q.front().second>i+y){
			q.pop_front();
		}
		if(q.front().second==i){
			loc=i;
		}
	}
	printf("%d\n",loc+1);
	return 0;
}