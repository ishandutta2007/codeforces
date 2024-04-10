#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long n,m,k,cnt,ans;
int main(){
	cin>>n>>m>>k;
	long long tmp;
	for(long long i=0;i<m;i++)cin>>tmp,a.push_back(tmp);
	long long i=0;
	while(i<a.size()){
		i++;
		while((a[i]-cnt-1)/k+1==((a[i-1]-cnt-1)/k+1)&&i<a.size())i++;
		cnt=i;
		ans++;
	}
	cout<<ans;
}