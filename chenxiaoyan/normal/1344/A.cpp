/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	set<int> st;
	for(int i=0;i<n;i++)st.insert(((i+v[i])%n+n)%n);
	puts(st.size()==n&&*--st.end()-*st.begin()+1==n?"YES":"NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}