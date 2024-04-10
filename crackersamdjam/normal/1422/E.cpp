#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

string s, ans[MM];
deque<char> cur;
int n, vis[MM], len[MM], t;
set<int> st;

set<int> in[30];

void add(int i){
	for(int j = 'a'; j <= 'z'; j++){
		if(j != s[i]){
			in[j-'a'].insert(i);
		}
	}
}
void rm(int i){
	for(int j = 'a'; j <= 'z'; j++){
		if(j != s[i]){
			in[j-'a'].erase(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	n = size(s);

	for(int i = n-1; i >= 0; i--){
		cur.push_front(s[i]);
		t++;
		add(i);
		auto it = in[cur[0]-'a'].begin();
		while(t >= 2 and !vis[i+1] and s[i] == s[i+1] and (it == in[cur[0]-'a'].end() or cur[0] >= s[*it])){
			cur.pop_front();
			cur.pop_front();
			vis[i+1] = 1;
			vis[i] = 1;
			rm(i+1);
			rm(i);
			t -= 2;
		}

		if(size(cur) > 10){
			for(int j = 0; j < 5; j++)
				ans[i] += cur[j];
			ans[i] += "...";
			ans[i] += cur[size(cur)-2];
			ans[i] += cur.back();
		}
		else{
			for(auto c: cur)
				ans[i] += c;
		}

		len[i] = t;
	}
	for(int i = 0; i < n; i++){
		cout<<len[i]<<' '<<ans[i]<<'\n';
	}
}