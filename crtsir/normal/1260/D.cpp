#include<bits/stdc++.h>
using namespace std;
long long l=0,r,mid,n,m,t,k,a[200003];
pair<pair<long long ,long long >,long long >trap[200003];
vector<pair<pair<long long,long long>,long long> >tmp;
bool check(long long x){
	tmp.clear();
	long long nowa=a[m-x],needtime=n,bst=-1;
	pair<pair<long long,long long>,long long>ttmp=make_pair(make_pair(-1,-1),-1);
	int i=0;
	for(i=0;i<k;i++)
		if(trap[i].second>nowa)
		{
			ttmp=trap[i];
			break;
		}
	if(ttmp.second==-1)return 1;
	for(i;i<k;i++)
		if(trap[i].second>nowa)
			if(ttmp.first.second>=trap[i].first.first)
				ttmp.first.second=max(trap[i].first.second,ttmp.first.second); 
			else
				tmp.push_back(ttmp),
				ttmp=trap[i];
		else;
	tmp.push_back(ttmp);
	//cout<<x<<":\n";
	//for(int i=0;i<tmp.size();i++)cout<<tmp[i].first.first<<' '<<tmp[i].first.second<<endl;
	//cout<<endl;
	if(x==0)nowa=2147483647;
	for(i=0;i<tmp.size();i++)
		if(tmp[i].first.second>bst){
			bst=tmp[i].first.second;
			needtime+=2*(tmp[i].first.second-tmp[i].first.first+1);
			if(needtime>t)return 0;
		}
//	cout<<x<<' '<<needtime<<endl;
	return 1;
}
int main(){
	scanf("%lld%lld%lld%lld",&m,&n,&k,&t);
	t--;
	for(long long  i=0;i<m;i++)scanf("%lld",&a[i]);
	for(long long  i=0;i<k;i++)scanf("%lld%lld%lld",&trap[i].first.first,&trap[i].first.second,&trap[i].second);
	sort(trap,trap+k);
	sort(a,a+m);
	r=m;
	while(l!=r){
		long long  mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
		if(r-l==1){l+=check(r);break;}
	}
	cout<<l;
}