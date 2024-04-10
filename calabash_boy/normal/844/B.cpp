#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool mp[MAX][MAX];
int m,n;
long long bas[MAX];
void calc(){
	bas[0]=1;
	bas[1]=2;
	for (int i=2;i<=50;i++){
		bas[i]=bas[i-1]*2;
	}
	for (int i=0;i<=50;i++){
		bas[i]--;
	}
}

int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>mp[i][j];
		}
	}
	calc();
	long long ans =0;
	for (int i=0;i<n;i++){
		int sum =0;
		for (int j=0;j<m;j++){
			if (mp[i][j]){
				sum++;
			}
		}
//		cout<<sum<<endl;
		ans +=bas[sum]+bas[m-sum];
	}
	for (int j=0;j<m;j++){
		int sum =0;
		for (int i=0;i<n;i++){
			if (mp[i][j]){
				sum++;
			}
		}
//		cout<<sum<<endl;
		ans+=bas[sum]+bas[n-sum]-n;
	}
	cout<<ans<<endl;
	return 0;
}