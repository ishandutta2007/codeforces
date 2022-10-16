#include<bits/stdc++.h>
using namespace std;
int n,m;
int bit[1000003];
long long find_sum(int x){
	long long sum=0;
	while(x){
//		cout<<bit[x];
		sum+=bit[x];
		x&=x-1;
	//	cout<<x<<' ';
	}
	//cout<<endl;
	return sum;
}
void adid(int x){
	while(x<=n){
		bit[x]++,
		x=(x|(x-1))+1;
	}
}
int main(){
	cin>>n>>m;
	int x=1;
	m=min(m,n-m);
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans++;
		int from=x-m+1,to=x+m-1;
		if(from<1)
			ans+=find_sum(to)+find_sum(n)-find_sum(from+n-1);
		else if(to>n)
			ans+=find_sum(n)-find_sum(from-1)+find_sum(to-n);
		else
			ans+=find_sum(to)-find_sum(from-1);
		cout<<ans<<' ';
		adid(x);
		x+=m;
		if(x>n)x-=n;
	}
}