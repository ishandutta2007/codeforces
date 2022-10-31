#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
map<long long ,long long > m1,m2;
long long a[MAXN];
long long sum;
int main(){
	int n;
	cin>>n;
	sum=0;
	for (int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		m1[a[i]]=i;
		sum+=a[i];
	}
	if (sum%2!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	for (int i=n-1;i>=0;i--){
		m2[a[i]]=i;
	}
	long long temp = sum/2;
	for (int i=0;i<n;i++){
		temp-=a[i];
		if (temp==0){
			cout<<"YES"<<endl;
			return 0;
		}
		if (m1[temp]>i){
			cout<<"YES"<<endl;
			return 0;
		}
		if (m2[-temp]!=0&&m2[-temp]<=i){
			cout<<"YES"<<endl;
			return 0;
		}
		if (a[0]==-temp){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}