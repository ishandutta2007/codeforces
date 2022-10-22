#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m,k;
char a[N];
int s0[N],s1[N];
vector<int> v;
int main(){
	int i,j;
	cin>>(a+1);
	n=1;while(a[n+1]) n++;
	for(i=1;i<=n;i++) s0[i]=s0[i-1]+(a[i]=='(');
	for(i=n;i;i--) s1[i]=s1[i+1]+(a[i]==')');
	for(i=0;i<=n;i++){
		if(!s0[i]&&!s1[i+1]){
			cout<<0;
			return 0;
		}
	}
	cout<<1<<endl;
	for(i=1;i<=n;i++)
		if(s0[i]==s1[i+1]) break;
	for(j=1;j<=i;j++) if(a[j]=='(') v.push_back(j);
	for(j=i+1;j<=n;j++) if(a[j]==')') v.push_back(j);
	cout<<v.size()<<endl;
	for(auto x:v) cout<<x<<" ";
	return 0;
}