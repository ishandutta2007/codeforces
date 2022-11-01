#include<bits/stdc++.h>
using namespace std;
struct Opt{
	int a,b;
	bool operator<(const Opt &y)const{
		return a<y.a;
	}
	bool operator>(const Opt &y)const{
		return a>y.a;
	}
};
vector<Opt>P,N;
priority_queue<int,vector<int>,greater<int> >Q;
int main(){
	int i,n,r,l,ans=0;
	scanf("%d%d",&n,&r);
	Opt d;
	for(i=0;i<n;i++){
		scanf("%d%d",&d.a,&d.b);
		if(d.b<0){
			N.push_back(d);
		}else{
			P.push_back(d);
		}
	}	
	sort(P.begin(),P.end());
	l=N.size();
	for(i=0;i<l;i++){
		N[i].a+=N[i].b;
		N[i].a=N[i].a; 
	}
	sort(N.begin(),N.end());
	reverse(N.begin(),N.end());
	l=P.size();
	for(i=0;i<l;i++){
		if(r>=P[i].a){
			r+=P[i].b,ans++;
		}
	}
	l=N.size();
	for(int i=0;i<l;i++){
		r+=N[i].b;
		Q.push(N[i].b);
		if(r<N[i].a){
			r-=Q.top();
			Q.pop();	
		}
	}
	if(r<0){
		ans--;
	}
	printf("%d",ans+Q.size());
	return 0;
}