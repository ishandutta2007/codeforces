#include<bits/stdc++.h>

using namespace std;
struct node{
	int x,y;
	bool operator <(const node &b)const
	{
		return x<b.x;
	}
};
set<node> s;
int n;
int main(){
	cin>>n;
	int i,j;
	cin>>i;
	node p;p.x=i;p.y=1;
	s.insert(p);
	for(i=2;i<=n;i++){
		int x;cin>>x;
		node p;p.x=x;p.y=i;
		auto it=s.upper_bound(p);
		auto it2=it;
		if(it==s.begin()){
			cout<<it->x<<" ";
			s.insert(p);
			continue;
		}
		it2--;
		if(it==s.end()){
			cout<<it2->x<<" ";
			s.insert(p);
			continue;
		}
		if(it->y>it2->y)
			cout<<it->x<<" ";
		else cout<<it2->x<<" ";
		s.insert(p);
	}
	return 0;
}