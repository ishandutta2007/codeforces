#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const int mod=1e9+7;
const int maxn=200005;

struct segment{
	int l,r,pos;
};

bool comp(segment x, segment y){
	return x.r>y.r;
}

bool comp2(segment x, segment y){
	return x.l<y.l;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin >> n >> k;
	segment seg[n];
	segment seg1;
	loop(n) cin >> seg[i].l >> seg[i].r;
	loop(n) seg[i].pos=i+1;
	int tel[maxn],num[maxn];
	loop(maxn) tel[i]=0;
	loop(n){
		tel[seg[i].l]++;
		tel[seg[i].r+1]--;
	}
	list<segment> List,list1,list2,removed;
	loop(n) list2.push_back(seg[i]);
	list2.sort(comp2);
	loop(maxn){
		if(list2.empty()) break;
		if(i==0) num[0]=tel[0];
		else num[i]=num[i-1]+tel[i];
		if(num[i]<=k) continue;
		while(list2.front().l<=i){
			seg1=list2.front();
			if(seg1.r>=i) list1.push_back(seg1);
			list2.pop_front();
			if(list2.empty()) break;
		}
		list1.sort(comp);
		List.merge(list1,comp);
		loopi(j,num[i]-k){
			if(List.empty()) break;
			if(List.front().r<i) break;
			tel[List.front().r+1]++;
			removed.push_back(List.front());
			List.pop_front();
		}
		num[i]=k;
	}
	cout << removed.size() << "\n";
	while(not removed.empty()){
		cout << removed.back().pos << ' ';
		removed.pop_back();
	}
	cout << "\n";
	return 0;
}