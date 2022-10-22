/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	cin>>n;
	vector<int> v;
	while(n--){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}