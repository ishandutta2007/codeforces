#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1<<8;
int n;
struct Expression{
	string a;
	inline Expression(){}
	inline Expression(string x){ a=x;}
	inline Expression(const char *x){ a=x;}
	inline bool valid(){ return !a.empty();}
	inline bool operator<(const Expression &r)const{
		if(a.empty()) return 0;
		if(r.a.empty()) return 1;
		if(a.length()!=r.a.length()) return a.length()<r.a.length();
		return a<r.a;
	}
} A[N], B[N], C[N];
inline Expression operator+(const Expression &a, const Expression &b){ return a.a+b.a;}
inline bool update(Expression &a, Expression b){
	if(b<a) return a=b, 1;
	return 0;
}
int main() {
	A[240]="x", A[204]="y", A[170]="z";
	bool ok;
	do{
		ok=0;
		for(int i=0; i<N; ++i) if(A[i].valid()) ok|=update(A[255^i], "!"+A[i]);
		for(int i=0; i<N; ++i) if(A[i].valid()) ok|=update(B[i], A[i]);
		for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(A[i].valid() && B[j].valid())
			ok|=update(B[i&j], A[i]+"&"+B[j]);
		for(int i=0; i<N; ++i) if(B[i].valid()) ok|=update(C[i], B[i]);
		for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) if(B[i].valid() && C[j].valid())
			ok|=update(C[i|j], B[i]+"|"+C[j]);
		for(int i=0; i<N; ++i) if(C[i].valid()) ok|=update(A[i], "("+C[i]+")");
	} while(ok);
	for(int i=0; i<N; ++i) A[i]=min(min(A[i], B[i]), C[i]).a;

	scanf("%d", &n);
	while(n--){
		static char s[9];
		scanf("%s", s);
		int x=0;
		for(int i=0; i<8; ++i) x+=((s[i]-'0')<<i);
		cout<<A[x].a<<endl;
	}
	return 0;
}