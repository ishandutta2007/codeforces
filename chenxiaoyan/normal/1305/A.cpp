/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> v1,v2;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v1.push_back(x);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v2.push_back(x);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";puts("");
	for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}