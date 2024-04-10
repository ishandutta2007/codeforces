#include <bits/stdc++.h>
const int N=1e6+5;
int n,k,q,id,num,len,now,a[N],lb[N],rb[N],ans[N],pos[N],cnt[N];
std::vector<int> px,py;
std::map<std::pair<int, int>,int> map;
struct Query{
	int i,l,r;
}que[N];
bool operator <(const Query &u, const Query &v){return pos[u.l]==pos[v.l]?u.r<v.r:u.l<v.l;}
int getid(int x, int y){
	int gcd=std::abs(std::__gcd(x, y));
	x/=gcd;y/=gcd;
	if (map.count({x, y})) return map[ {x, y}];
	return map[{x,y}]=id++;
}
void insert(int x){
	cnt[x]++;
	if (cnt[x]==1) now++;
}
void erase(int x){
	cnt[x]--;
	if (cnt[x]==0) now--;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin>>n;
	for (int i=0;i<n;i++) {
		std::cin>>k;
		px.clear(); py.clear();
		for (int j=0;j<k;j++) {
			int k1,k2;
			std::cin>>k1>>k2;
			px.push_back(k1);
			py.push_back(k2);
		}
		lb[i]=num;
		for (int j=0;j<k;j++) a[num++]=getid(px[(j+1)%k]-px[j],py[(j+1)%k]-py[j]);
		rb[i]=num-1;
	}
	len=sqrt(num);
	for (int i=0;i<num;i++) pos[i]=i/len;
	std::cin>>q;
	for (int i=0;i<q;i++) {
		que[i].i=i;
		int k1,k2;
		std::cin>>k1>>k2;
		que[i].l=lb[k1-1];
		que[i].r=rb[k2-1];
	}
	std::sort(que,que+q);
	for (int i=0,l=0,r=-1;i<q;i++) {
		while (r<que[i].r) insert(a[++r]);
		while (r>que[i].r) erase(a[r--]);
		while (l>que[i].l) insert(a[--l]);
		while (l<que[i].l) erase(a[l++]);
		ans[que[i].i]=now;
	}
	for (int i=0;i<q;i++)  printf("%d\n",ans[i]);
	return 0;
}