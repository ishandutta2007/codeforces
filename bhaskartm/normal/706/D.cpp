#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int q;
	cin>>q;
	multiset<int>s;
	s.insert(0);
	while(q--){
		char c;
		cin>>c;
		if(c=='+'){
			int x;
			cin>>x;
			s.insert(x);
		}
		else if(c=='-'){
			int x;
			cin>>x;
			s.erase(s.find(x));
		}
		else{
			int num=0;
			int x;
			cin>>x;
			for(int i=32; i>=0; i--){
				if((x & (1LL<<i))==(1LL<<i)){
					auto it=s.lower_bound(num);
					int val=(*it);
					if((val & (1LL<<i))==(1LL<<i)){
						num+=(1LL<<i);
					}
				}
				else{
					auto it=s.lower_bound(num+(1LL<<i));
					if(it==s.end()){
						continue;
					}
					if(*(it)<num+(1<<(i+1))){
						num+=(1LL<<i);
					}
					
				}
			}
			
			cout<<(num^x)<<endl;
		}
	}
	return 0;
}