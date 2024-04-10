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
const int MM = 2e5+5;

int n, a[MM], cnt[60], va[MM], vb[MM], ans = 1e9;
vector<int> adj[MM];

struct node{
	node* ch[2] = {nullptr, nullptr};
	int id = -1, sz = 0, val = 0;
	void go(int lvl){
		// if(~id) cout<<"id "<<id<<endl;
		if(ch[0] and ch[1]){
			// print(lvl);
			ch[0]->go(lvl-1);
			ch[1]->go(lvl-1);
			sz += ch[0]->sz + ch[1]->sz;
			val = min(ch[0]->sz-1 + ch[1]->val, ch[0]->val + ch[1]->sz-1);
			//merging
			// cout<<lvl<<' '<<sz<<' '<<val<<" ret\n";
		}
		else if(ch[0]){
			ch[0]->go(lvl-1);
			sz += ch[0]->sz;
			val = ch[0]->val;
		}
		else if(ch[1]){
			ch[1]->go(lvl-1);
			sz += ch[1]->sz;
			val = ch[1]->val;
		}
		// print(lvl, sz, val);
	}
};

int main(){
	node *rt = new node();
	scan(n);
	for(int i = 0; i < n; i++)
		scan(a[i]);

	for(int i = 0; i < n; i++){
		node *cur = rt;

		cur = rt;
		for(int j = 32; j >= 0; j--){
			bool d = a[i]&(1LL<<j) ? 1 : 0;
			if(!cur->ch[d])
				cur->ch[d] = new node();
			cur = cur->ch[d];
		}
		cur->id = i;
		cur->sz = 1;
	}

	rt->go(32);
	ans = rt->val;

	print(ans);
}