#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
long long a[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	long long ans=0;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
			a[i]=0;
		}else{
			while(a[i]!=3&&a[i]>=2&&cnt>0){
				a[i]-=2;
				cnt--;
				ans++;
			}
		}
	}
	long long sm=0;
	for(int i=1;i<=n;i++){
		sm+=a[i];
	}
	cout<<ans+(sm/3);
	return 0;
}