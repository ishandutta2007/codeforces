/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int x[12];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
}
int main(){
	for(int i=0;i<12;i++)cin>>x[i],nums.pb(x[i]);
	discrete();
	for(int i=0;i<12;i++)x[i]=lower_bound(nums.begin(),nums.end(),x[i])-nums.begin();
	for(double i=x[0];i<=x[2];i+=.5)for(double j=x[1];j<=x[3];j+=.5)
		if(!(x[4]<=i&&x[5]<=j&&x[6]>=i&&x[7]>=j)&&!(x[8]<=i&&x[9]<=j&&x[10]>=i&&x[11]>=j))
			return puts("YES"),0;
	puts("NO");
	return 0;
}