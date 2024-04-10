/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	set<int> st;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)st.insert(a[j]-a[i]);
	cout<<st.size()<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}