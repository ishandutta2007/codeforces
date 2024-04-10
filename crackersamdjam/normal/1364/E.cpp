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
const int MM = 2069;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 g1(0);
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}

int n, ans[MM], a[MM], ac;

vector<int> p = {-1, 1, 0, 2};

#define ONLINE

void gen(){
	n = randint(3, 2048);
	p.clear();
	for(int i = 0; i < n; i++)
		p.emplace_back(i);
	shuffle(all(p), g1);
	p.insert(p.begin(), -1);
	n = p.size()-1;
//	for(int i: p)
//		cout<<i<<' ';
//	cout<<endl;
//	exit(0);
}

int ask(int i, int j){
	ac++;
	if(ac > 4269)
		abort();
	cout<<"? "<<i<<' '<<j<<endl;
	assert(i != j);
#ifdef ONLINE
	int v;
	cin>>v;
	return v;
#else
	return p[i]|p[j];
#endif
}

int main(int argc, char *args[]){
#ifdef ONLINE
	cin>>n;
#else
	int sd = argc > 1 ? atoi(args[1]) : 0;
	g1 = mt19937(sd);
	gen();
#endif
	for(int i = 1; i <= n; i++)
		a[i] = i;
	shuffle(a+1, a+1+n, g1);
	
	int x = a[1], y = a[2], last = ask(x, y);
	for(int i = 3; i <= n; i++){
		int v = ask(y, a[i]);
		if(v < last){
			x = a[i];
			last = v;
		}
		else if(v > last){
			//a[i] is bad
		}
		else{
			//y can not be 0
			y = a[i];
			last = ask(x, y);
		}
	}
	
	int id;
	while(1){
		int i = randint(1, n);
		if(i == x or i == y)
			continue;
		int vx = ask(x, i), vy = ask(y, i);
		if(vx != vy){
			id = vx < vy? x: y;
			break;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] != id)
			ans[a[i]] = ask(a[i], id);
	}
	cout<<"!";
	for(int i = 1; i <= n; i++)
		cout<<' '<<ans[i];
	cout<<endl;
	
	sort(ans+1, ans+1+n);
	for(int i = 1; i <= n; i++)
		assert(ans[i] == i-1);
}