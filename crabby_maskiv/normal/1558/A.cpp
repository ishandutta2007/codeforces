#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		int A,B;cin>>A>>B;
		set<int> st;
		int X=(A+B>>1);
		int Y=A+B-X;
		for(int a=0;a<=A;a++){
			int b=A-a,c=X-a;
			int d=B-c;
			if(b>=0&&c>=0&&d>=0) st.insert(b+c);
		}
		if(X!=Y){
			swap(X,Y);
			for(int a=0;a<=A;a++){
				int b=A-a,c=X-a;
				int d=B-c;
				if(b>=0&&c>=0&&d>=0) st.insert(b+c);
			}
		}
		cout<<st.size()<<endl;
		for(auto x:st) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}