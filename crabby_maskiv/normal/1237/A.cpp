#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20005;
const ll inf=0x3f3f3f3fll;
int n,m;
int a[N];
int b[N];
int main(){
	int i,j;
	cin>>n;
	int cnt;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0) b[i]=a[i]/2;
		else cnt++;
	}
	int cnt2=0;
	for(i=1;i<=n;i++){
		if(a[i]%2){
			if(cnt2<cnt/2) a[i]=(a[i]+1)/2;
			else a[i]=(a[i]-1)/2;
			b[i]=a[i];
			cnt2++;
		}
	}
	for(i=1;i<=n;i++) cout<<b[i]<<endl;
	return 0;
}