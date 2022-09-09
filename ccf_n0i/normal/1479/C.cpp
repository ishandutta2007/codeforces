#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int i,j,l,r,n,m,id[1<<20];
vector<pair<pair<int,int>,int> > ans;
void add(int x,int y,int z){
	ans.push_back(make_pair(make_pair(x,y),z));
}
int main(){
	cin>>l>>r;
	if(l==r){
		puts("YES");
		puts("2 1");
		printf("1 2 %d\n",l);
		return 0;
	}
	n=23;
	for(i=1;i<(1<<20);i<<=1){
		id[i]=--n;
	}
	n=23;
	for(i=1;i<(1<<20);i<<=1){
		ans.push_back(make_pair(make_pair(id[i],n),1));
		for(j=(i>>1);j;j>>=1){
			ans.push_back(make_pair(make_pair(id[i],id[j]),j));
		}
	}
//	add(1,2,1);
	
	add(1,n,1);
	m=r-l;
	for(i=1;i<(1<<20);i<<=1){
		if(m&i){
			m^=i;
			add(1,id[i],m+1);
		}
	}
	puts("YES");
	printf("%d %d\n",n,(int)ans.size());
	dzd(ans,it){
//		if(it->first.first==id[1]) it->first.first=n;
//		else if(it->first.first==n) it->first.first=id[1];
//		if(it->first.second==id[1]) it->first.second=n;
//		else if(it->first.second==n) it->first.second=id[1];
		printf("%d %d %d\n",it->first.first,it->first.second,it->second+(it->first.second==n)*(l-1)); 
	}
	return 0;
}