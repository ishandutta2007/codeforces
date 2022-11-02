#include<bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; ++i)
#define MAX 1000900
class djs{
public:
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int l[MAX];
string s;
stack<int> cc;
int main()
{	
	cin.tie(0) , cout.sync_with_stdio(0);
	cin >> s;
	ds.init();
	
	int ok = 0;
	REP(i , 0 , s.size()){
		if(s[i] == '(') cc.push(i + 1);
		else if(cc.size()){
			int tmp = cc.top(); cc.pop();
			l[i + 1] = tmp;
			ok = 1;
		}
	}
	if(ok == 0) cout << "0 1" << endl;
	else {
		int cnt = 0 , mm = 0;
		REP(i , 1 , s.size() + 1){
			if(l[i] != 0){
				int tmp = l[i] - 1;
				if(l[tmp] != 0) ds.Union(i , tmp);
				tmp = l[ds[i]];
				if(i - tmp + 1 > mm) mm = i - tmp + 1 , cnt = 1;
				else if(i - tmp + 1 == mm) cnt ++;
			}
		}
		cout << mm << " " << cnt << endl;
	}
	return 0;
}