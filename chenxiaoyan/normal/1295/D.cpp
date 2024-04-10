/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void mian(){
	int a,b;
	cin>>a>>b;
	b/=gcd(a,b);
	int cpy=b;
	set<int> st;
	for(int i=2;i<=sqrt(b);i++)
		while(b%i==0)st.insert(i),b/=i;
	if(b>1)st.insert(b);
	for(set<int>::iterator i=st.begin();i!=st.end();i++)cpy/=*i,cpy*=*i-1;
	cout<<cpy<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
3
4 9
5 10
42 9999999967
*/