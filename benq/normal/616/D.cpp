#include<iostream>
using namespace std;
const int maxn=1e6+5;

int a[maxn],num[maxn];

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int cnt=0, p1, p2, len=0,j=0;
	for(int i=0; i<n; i++) {
		num[a[i]]++;
		if(num[a[i]] == 1) cnt++;
		while(cnt>k){
			num[a[j]]--;
			if(num[a[j]]==0) cnt--;
			j++;
		}
		if(i-j+1>len) {
			len=i-j+1;
			p1=j+1;
			p2=i+1;
		}
	}
	cout<<p1<<" "<<p2<<endl;
}