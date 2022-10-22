/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int a,b,n;
	cin>>a>>b>>n;
	set<int> st;
	while(n--){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(int i=0;;i++)if(b-i>0&&st.find(b-i)==st.end()||b+i<=a&&st.find(b+i)==st.end()){cout<<i<<"\n";break;}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian(); 
	return 0;
}