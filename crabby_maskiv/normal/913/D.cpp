#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=1000000007ll;
int n,m;
ll t;
struct node{
	int a,id;
	ll t;
	bool operator <(const node &b)const
	{
		return t<b.t;
	}
}a[N];
vector<int> v;
bool check(int key){
	v.clear();
	int cnt=0;ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].a<key) continue;
		if(a[i].t+sum<=t){
			cnt++;
			sum+=a[i].t;
			v.push_back(a[i].id);
		}
		if(cnt>=key) return 1;
	}
	return 0;
}
int main(){
	int i,j;
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>a[i].a>>a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(r>l){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l-1<<endl<<l-1<<endl;
	check(l-1);
	for(i=0;i<v.size();i++) cout<<v[i]<<" ";
    return 0;
}