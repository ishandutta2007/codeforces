/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n;
	vector<int> v;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=0;i+1<v.size();i++)sum+=v[i];
	puts(sum<v.back()?"T":(sum&1)==(v.back()&1)?"HL":"T");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}