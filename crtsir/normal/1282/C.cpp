#include<bits/stdc++.h>
using namespace std;
long long ti[200003],tp[200003];
long long n,t,a,b;
vector<long long>easy,hard,pr;
long long find1(long long ts){
	if(!easy.size())return 0;
	long long l=0,r=easy.size()-1;
	if(ts<easy[0])return 0;
	while(l!=r){
		long long mid=(l+r)/2;
		if(easy[mid]<=ts)
			l=mid;
		else
			r=mid-1;
		if(easy[l+1]<=ts)l++;
		if(easy[r]>ts)r--;
	}
	return l+1;
}
long long find2(long long ts){
	if(!hard.size())return 0;
	long long l=0,r=hard.size()-1;
	if(ts<hard[0])return 0;
	while(l!=r){
		long long mid=(l+r)/2;
		if(hard[mid]<=ts)
			l=mid;
		else
			r=mid-1;
		if(hard[l+1]<=ts)l++;
		if(hard[r]>ts)r--;
	}
	return l+1;
}
long long check(long long ts){
	long long mste=find1(ts),msth=find2(ts);
	long long lasttime=ts-mste*a-msth*b;
	if(lasttime<0)return 0;
	if(a*easy.size()+b*msth<=ts)
		return(easy.size()+(ts-easy.size()*a)/b);
	else
		return(msth+mste+(lasttime)/a); 
}
int main(){
	long long T; 
	cin>>T;
	while(T--){
		cin>>n>>t>>a>>b;
		easy.clear();hard.clear();pr.clear();
		for(long long i=0;i<n;i++)scanf("%d",&tp[i]);
		for(long long i=0;i<n;i++)scanf("%d",&ti[i]);
		for(long long i=0;i<n;i++)
			if(tp[i])
				hard.push_back(ti[i]),
				pr.push_back(ti[i]);
			else
				easy.push_back(ti[i]),
				pr.push_back(ti[i]);
		if(a*easy.size()+b*hard.size()<=t){
			cout<<n<<endl;
			continue;
		}
		sort(easy.begin(),easy.end());
		sort(hard.begin(),hard.end());
		sort(pr.begin(),pr.end());
		long long ans=check(t);
		for(long long i=0;i<pr.size();i++)
			if(pr[i]-1>=a)
				ans=max(ans,check(pr[i]-1));
		cout<<max(ans,0ll)<<endl;
	}
}