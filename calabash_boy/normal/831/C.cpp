#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
set<int> S1,S2;
int score[MAXN],delta[MAXN],sum[MAXN];
int k,n;
int main(){
	cin>>k>>n;
	for (int i=1;i<=k;i++){
		cin>>delta[i];
		sum[i]=sum[i-1]+delta[i];
	}
	for (int i=1;i<=n;i++){
		cin>>score[i];
	}
	for (int i=1;i<=n;i++){
		S2.clear();
		for (int j=1;j<=k;j++){
			if (i==1||S1.find(score[i]-sum[j])!=S1.end()){
				S2.insert(score[i]-sum[j]);
//				cout<<score[i]-sum[j]<<endl;
			}
		}
		S1=S2;
	}
	cout<<S1.size();
	return 0;
}