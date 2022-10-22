#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll mod=1000000007ll;
int n,m;
struct node{
	int x,y;ll d;
	node(int x,int y,ll d):x(x),y(y),d(d){}
};
vector<node> v;
stack<int> s;
pair<int,ll> a[N];
ll b[N];
bool c[N];
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
	for(i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
		if(a[i].first<b[i]) c[i]=1;
	for(i=1;i<=n;i++){
		if(c[i]) s.push(i);
		else{
			while(a[i].first>b[i]){
				if(s.empty()){
					cout<<"NO";
					return 0;
				}
				int p=s.top();
				if(b[p]-a[p].first>a[i].first-b[i]){
					v.push_back(node(a[p].second,a[i].second,a[i].first-b[i]));
					a[p].first+=a[i].first-b[i];
					a[i].first=b[i];
				}
				else{
					v.push_back(node(a[p].second,a[i].second,b[p]-a[p].first));
					a[i].first-=b[p]-a[p].first;
					a[p].first=b[p];
					s.pop();
				}
			}
		}
	}
	if(!s.empty()){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<v.size()<<endl;
	for(i=0;i<v.size();i++){
		cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].d<<endl;
	}
	return 0;
}