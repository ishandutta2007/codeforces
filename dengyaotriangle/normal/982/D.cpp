#include<bits/stdc++.h>

using namespace std;

const int maxn=100006;

struct poi{
	int i,v;
};

poi p[maxn];
int n;
int a[maxn];
set<int> s;
int cnt[maxn],cnf,cnh;
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		p[i].i=i;p[i].v=a[i];	
	}
	sort(p+1,p+1+n,[&](poi a,poi b){
		return a.v>b.v;
	});
	s.insert(0);s.insert(n+1);		
	cnt[n]=1;
	cnf=1;cnh=1;
	int mxl=1,mxk=p[1].v+1; 
	for(int i=1;i<=n;i++){
		int pl=p[i].i;
		set<int>::iterator itr=s.upper_bound(pl),itl=itr;itl--;
		cnt[(*itr)-(*itl)-1]--;cnh--;
		if(cnt[(*itr)-(*itl)-1]==0) cnf--;
		if(pl-(*itl)-1!=0){
			if(cnt[pl-(*itl)-1]==0)cnf++; 
			cnt[pl-(*itl)-1]++;cnh++;
		}
		if((*itr)-pl-1!=0){
			if(cnt[(*itr)-pl-1]==0) cnf++;
			cnt[(*itr)-pl-1]++;cnh++;
		}
		s.insert(pl); 
		if(cnf==1){
			if(cnh>=mxl){
				mxl=cnh;
				mxk=p[i+1].v+1;
			}
		} 
	}
	cout<<mxk;
	return 0;
}