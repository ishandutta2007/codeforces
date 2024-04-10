#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

int t, n, x, y, a[MM], b[MM];
vector<int> v[MM];

int main(){
	scan(t);
	while(t--){
		bool no = 0;
		scan(n, x, y);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			b[i] = 0;
			v[a[i]].emplace_back(i);
		}
		priority_queue<pair<int, int>> q;
		int z = -1;
		for(int i = 1; i <= n+1; i++){
			if(v[i].empty()){
				z = i;
			}
			else{
				q.push({(int)v[i].size(), i});
			}
		}
		// assert(~z);
		
		if(y < x){
			no = 1;
			goto out;
		}

		while(x > 0){
			x--;
			y--;
			//get most common first
			auto rm = q.top(); q.pop();
			int id = rm.second;
			int i = v[id].back(); v[id].pop_back();
			b[i] = id;
			// cout<<"x"<<endl;
			if(--rm.first)
				q.push(rm);
		}
		//if odd, try to make 3-cycle
		//then 2-cycle
		//if still odd (failed 3), then throw at the end
		if(y%2 == 1 and y >= 3){
			if(q.size() >= 3){
				//make a three
				y -= 3;
				// cout<<"y3"<<endl;
				auto ra = q.top(); q.pop();
				auto rb = q.top(); q.pop();
				auto rc = q.top(); q.pop();
				int ida = ra.second;
				int idb = rb.second;
				int idc = rc.second;

				int ia = v[ida].back(); v[ida].pop_back();
				int ib = v[idb].back(); v[idb].pop_back();
				int ic = v[idc].back(); v[idc].pop_back();

				b[ia] = idb;
				b[ib] = idc;
				b[ic] = ida;
				if(--ra.first)
					q.push(ra);
				if(--rb.first)
					q.push(rb);
				if(--rc.first)
					q.push(rc);
			}
		}
		while(y >= 2){
			if(q.size() >= 2){
				//make a two
				// cout<<"y2"<<endl;
				y -= 2;
				auto ra = q.top(); q.pop();
				auto rb = q.top(); q.pop();
				int ida = ra.second;
				int idb = rb.second;

				int ia = v[ida].back(); v[ida].pop_back();
				int ib = v[idb].back(); v[idb].pop_back();

				b[ia] = idb;
				b[ib] = ida;
				if(--ra.first)
					q.push(ra);
				if(--rb.first)
					q.push(rb);
			}
			else{
				no = 1;
				goto out;
			}
		}

		if(y >= 1){
			//last one
			if(q.size() >= 2){
				// cout<<"y1"<<endl;
				y--;
				auto ra = q.top(); q.pop();
				auto rb = q.top(); q.pop();
				int ida = ra.second;
				int idb = rb.second;

				int ia = v[ida].back(); v[ida].pop_back();
				// int ib = v[idb].back(); v[idb].pop_back();

				b[ia] = idb;
				//throw the other one
			}
			else{
				no = 1;
			}
		}

		out:;
		// print(no, x, y);
		if(no or y){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i = 0; i < n; i++)
				printf("%d ", b[i] ? b[i] : z);
			pc(10);
		}

		for(int i = 1; i <= n+1; i++){
			v[i].clear();
		}
	}
}