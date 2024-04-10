#include<bits/stdc++.h>
using namespace std;
int n,m,d,lt[1003],ans[1003],cnt;
int main(){
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)cin>>lt[i],cnt+=lt[i];
	if(cnt+(m+1)*(d-1)<n){
		cout<<"NO";
		return 0;
	}
	cnt=n-cnt;
	int j=0,dis=1;
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		if(cnt>0&&dis<d)
			dis++,
			cnt--,
			cout<<0<<' ';
		else{
			int to=i+lt[j];
			for(i;i<to;i++)cout<<j+1<<' ';i--;
			j++;
			dis=1;
		}
	}
}