#include<bits/stdc++.h>
using namespace std;
long long n,a[100003],x=-1,cnt,ans=100000000000000;
long long check(long long fr,long long to,long long ps){
	long long ret=0;
	for(long long i=fr;i<to;i++)
		ret+=a[i]*fabs(i-ps);
	return ret;
}
bool isprime(int x){
	if(x==1||x==0)return 0;
	for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;
	return 1; 
}
vector<int>v; 
int main(){
	cin>>n;
	for(long long i=0;i<n;i++)scanf("%lld",&a[i]),cnt+=a[i];
	for(long long i=cnt;i>=2;i--)
		if(cnt%i==0&&isprime(i))
			v.push_back(i);
	if(v.empty()){
		cout<<-1;
		return 0;
	}
	cnt=0;
	for(int kk=0;kk<v.size();kk++){
		x=v[kk];
		long long pos,from=0,to=0,res=0;
		for(long long i=0;i<n;i++){
			to=i+1;cnt+=a[i];
			if(cnt==x)
				res+=check(from,to,pos),
				cnt=0,
				from=i+1;
			else
				if(cnt==(x+1)/2&&a[i])
				pos=i;
		}
		ans=min(res,ans);
	}
	cout<<ans;
}