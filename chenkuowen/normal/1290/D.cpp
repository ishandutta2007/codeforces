#include<bits/stdc++.h>
using namespace std;
int n,k,g,top;
vector<int> a[1030];
bool query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	static char s[15];
	scanf("%s",s);
	return s[0]=='Y';
}
void clr(){ puts("R"); fflush(stdout); }
void finish(int x){ printf("! %d\n",x); exit(0); }
void ask(int i){
	vector<int> b;
	for(auto x:a[i]){
		if(!query(x)) b.push_back(x);
	}
	a[i]=b;
}
void shift2(vector<int>& a){
	int x=a[0],y=a[1];
	for(int i=2;i<a.size();++i)
		a[i-2]=a[i];
	a[(int)a.size()-2]=x;
	a[(int)a.size()-1]=y;
}
void solve(vector<int> a){
	if(a.size()<=2){
		clr();
		for(auto x:a)
			ask(x);
		return;
	}
	vector<int> x(a.begin(),a.begin()+a.size()/2);
	vector<int> y(a.begin()+a.size()/2,a.end());
	solve(x); solve(y);
	for(int i=0;i<x.size()/2;++i){
		clr();
		for(int j=0;j<x.size();++j){
			ask(x[j]); ask(y[j]);
		}
		clr();
		ask(x[0]); ask(y.back());
		shift2(x);
	}
}
int main(){
	scanf("%d%d",&n,&k); g=max(k/2,1); top=n/g;
	for(int i=1;i<=top;++i)
		for(int j=(i-1)*g+1;j<=i*g;++j)
			a[i].push_back(j);
	vector<int> x;
	for(int i=1;i<=top;++i) x.push_back(i);
	solve(x);
	int ans=0;
	for(int i=1;i<=top;++i)
		ans+=(int)a[i].size();
	finish(ans);
	return 0;
}