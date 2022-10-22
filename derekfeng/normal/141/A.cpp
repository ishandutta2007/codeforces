#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int main(){
	cin>>a>>b>>c;
	b+=a;
	sort(c.begin(),c.end()),sort(b.begin(),b.end());
	puts(c==b?"YES":"NO");
}