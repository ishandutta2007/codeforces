#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	int a=0;
	for(int i=0;i<s.size();i++){
		a+=(s[i]=='1'?1:0);
	}
	if(s=="0")printf("0\n");
	else printf("%d\n",((int)s.size()+1)/2-((a==1&&(((int)s.size()+1)%2==0))?1:0));
	return 0;
}