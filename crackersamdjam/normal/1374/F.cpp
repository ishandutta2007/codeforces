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
const int MM = 505;

int t, n, a[MM];
vector<int> v;

void add(int i){
	v.emplace_back(i);
	swap(a[i], a[i+2]);
	swap(a[i+1], a[i+2]);
}

void peek(string s){
	cout<<s<<endl;
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	pc(10);
}

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 0; i < n; i++)
			scan(a[i]);
		v.clear();
		int ok = -1;
		for(int st = 0; st < n; st++){
			int mn = 600, id = -1;
			for(int i = st; i < n; i++){
				if(a[i] < mn){
					mn = a[i];
					id = i;
				}
			}
			// print(st, id, a[id]);
			if(id == st){
				if(st and a[st] == a[st-1])
					ok = st;
				continue;
			}

			//move to right spot
			while(id >= st+2){
				id -= 2;
				add(id);
			}
			if(id == st+1){
				if(id == n-1){
					if(ok != -1){

						// peek("before");
						id--;
						while(id-2 > ok){
							add(id-2);
							add(id+1-2);
							id -= 2;
						}
						if(id == ok+2){
							//
							add(ok+1);
							add(ok+1);
						}
						// cout<<"id "<<id<<' '<<a[id]<<endl;
						// cout<<"ok "<<ok<<' '<<a[ok]<<endl;
						// peek("in");
						//now in place
						add(ok-1);
						add(ok-1);
						add(ok);
						add(ok);

						//now bring back up
						id = ok+3;
						while(id < n){
							add(id-2);
							id++;
						}
					}
					else if(id-2 >= 0 and a[id-2] == a[id]){
						add(id-2);	
					}
					else{
						goto no;
					}
				}
				else{
					//right once then shift
					id--;
					add(id);
					add(id);
				}
			}
			if(st and a[st] == a[st-1])
				ok = st;
		}
		// if(v.size() > n*n)
			// goto no;
		print(v.size());
		for(int i: v)
			printf("%d ", i+1);
		pc(10);
		// peek("done");
		continue;

		no:;
		print(-1);
		// for(int i: v)
			// printf("%d ", i+1);
		// pc(10);
		// for(int i = 0; i < n; i++)
			// printf("%d ", a[i]);
		// pc(10);
	}
}