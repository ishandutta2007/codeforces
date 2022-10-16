#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+5;

int t, n, a[MM];

int main(){
#ifdef CLION
	freopen("../in", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin>>t;
	while(t--){
		deque<deque<int>> q;
		vector<int> rm;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			q.push_back({i});
		}
		q.emplace_back(move(q.front()));
		q.pop_front();
		
		while(size(q) > 1){
			
			// pr(size(q), q.front().front(), q.back().back());
			if(__gcd(a[q.front().front()], a[q.back().back()]) > 1){
				// pr("merge");
				//small to large merge
				if(size(q.front()) < size(q.back())){
					while(size(q.front())){
						q.back().emplace_back(q.front().front());
						q.front().pop_front();
					}
					q.pop_front();
				}
				else{
					while(size(q.back())){
						q.front().emplace_front(q.back().back());
						q.back().pop_back();
					}
					q.pop_back();
					q.emplace_back(move(q.front()));
					q.pop_front();
				}
			}
			else{
				// pr("pop", q.front().front(), a[q.front().front()]);
				rm.emplace_back(q.front().front());
				q.front().pop_front();
				if(size(q.front())){
					q.emplace_back(move(q.front()));
					q.pop_front();
				}
				else{
					q.pop_front();
					//skip next one
					q.emplace_back(move(q.front()));
					q.pop_front();
				}
			}
		}
		//may still be problem within one group...
		//back and front, keep poping front until okay
		while(size(q[0]) and __gcd(a[q[0][0]], a[q[0].back()]) == 1){
			rm.emplace_back(q[0][0]);
			q[0].pop_front();
		}
		
		cout<<size(rm)<<' ';
		for(int i: rm)
			cout<<i+1<<' ';
		cout<<'\n';
		// cout<<"__________________\n";
		// pr(size(rm), "___________________");
	}
}