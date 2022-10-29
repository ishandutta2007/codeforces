#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=107;
int n;
string s,t;
inline void work(){
	cin>>s>>t;
	sort(s.begin(),s.end());
	if(t=="abc" && s[0]=='a'){
		auto it=s.begin(),it1=s.end();
		while(it!=s.end() && (*it)<'b')it++;
		while(it1!=s.begin() && (*(--it1))>'c');
		it1++;
		reverse(it,it1);
	}
	cout<<s<<endl;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}