#include <iostream>
#include <cstdio>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
void write(int x){
	if (x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
	return;
}
mt19937 rnd(time(NULL));
int tot,u[505],v[505];
int ask(vector<int> s,vector<int> t,int u){putchar('\n');
	write(s.size()),putchar('\n');
	for (int i=0;i<s.size();i++)write(s[i]),putchar(' ');putchar('\n');
	write(t.size()),putchar('\n');
	for (int i=0;i<t.size();i++)write(t[i]),putchar(' ');putchar('\n');
	write(u),putchar('\n');putchar('\n');
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans;
}
int find_root(vector<int> a){
	vector<int> s,t;
	s.push_back(a[0]),t.push_back(a[1]);
	for (int i=2;i<a.size();i++){
		if (rnd()%2==0)s.push_back(a[i]);
		else t.push_back(a[i]);
	}
	int mx=-1,id=0;
	for (int i=0;i<a.size();i++){
		int r=ask(s,t,a[i]);
		if (r>mx)mx=r,id=a[i];
	}
	return id;
}
int lc,ld,id[505];
vector<int> c[505],d[505];
void ins(int rt,int x){
	if (lc==0){
		++lc;
		c[lc].push_back(x);
		return;
	}
	vector<int> s,t;
	s.push_back(x);
	for (int i=1;i<=lc;i++)
		for (int j=0;j<c[i].size();j++)t.push_back(c[i][j]);
	int num=t.size()-ask(s,t,rt);
	if (num==0){
		++lc;
		c[lc].push_back(x);
		return;
	}
	ld=0;
	for (int i=1;i<=lc;i++)
		if (c[i].size()==num)++ld,id[ld]=i,d[ld]=c[i];
	int l=1,r=ld;
	while(l<r){
		int mid=(l+r)/2;
		t.clear();
		for (int i=l;i<=mid;i++)
			for (int j=0;j<(int)d[i].size();j++)
				t.push_back(d[i][j]);
		if (t.size()==ask(s,t,rt))l=mid+1;
		else r=mid;
	}
	c[id[l]].push_back(x);
	return;
}
void work(vector<int> a){
	if (a.size()==2){
		++tot;
		u[tot]=a[0],v[tot]=a[1];
		return;
	}
	shuffle(a.begin(),a.end(),rnd);
	int rt=find_root(a);
	for (int i=1;i<=lc;i++)c[i].clear();
	lc=0;
	for (int i=0;i<a.size();i++)
		if (a[i]!=rt)ins(rt,a[i]);
	vector<int> _c[505];
	int _lc=lc;
	for (int i=1;i<=_lc;i++)_c[i]=c[i],_c[i].push_back(rt);
	for (int i=1;i<=_lc;i++)work(_c[i]);
	return;
}
int main(){
	int n;
	cin>>n;
	vector<int> s;
	for (int i=1;i<=n;i++)s.push_back(i);
	work(s);
	puts("ANSWER");
	for (int i=1;i<=tot;i++)cout<<u[i]<<' '<<v[i]<<endl;
	return 0;
}
//qwq