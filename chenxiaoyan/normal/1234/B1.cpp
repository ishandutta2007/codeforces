/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define ppb pop_back()
#define pf push_front
int n,m;
set<int> s;
deque<int> q;
int main(){
	cin>>n>>m;
	while(n--){
		int x;
		cin>>x;
		if(s.find(x)!=s.end())continue;
		s.insert(x);
		if(q.size()==m)s.erase(q.back()),q.ppb;
		q.pf(x);
	}
	cout<<q.size()<<"\n";
	for(int i=0;i<q.size();i++)cout<<q[i]<<" ";
	return 0;
}