#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

long long a[maxn];
long long b[maxn];
long long n,m;
long long cnt=0;
long long sum=0;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	a[0]=0;
	long long cd=0;
	for(int i=1;i<=n;i++){
		long long cur=a[i]-a[i-1];
		cnt+=cur;
		cd+=cur;
		if(cd==0&&cur==0){
			cnt++;
			cd++;
		}
		cd--;
	}
	cout<<sum-cnt;
	return 0;
}