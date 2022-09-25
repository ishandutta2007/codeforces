#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	int q,a,b,x,num,l;
	int arr[2];
	bool t;
	cin >> q;
	string str;
	stack<int> s;
	for(int i=0; i<q; i++){
		cin >> a >> b >> str;
		x=num=arr[0]=arr[1]=0;
		t=false;
		for(int j=0; j<str.size(); j++){
			if(str[j]=='.'){
				x++;
				if(j==str.size()-1&&x>=b){
					s.push(x);
					num++;
				}
			}
			else{
				if(x>=b){
					s.push(x);
					num++;
				}
				x=0;
			}
		}
		for(int j=0; j<num; j++){
			if(s.top()<a){
				for(int k=0; k<num-j; k++) s.pop();
				cout << "NO" << endl;
				t=true;
				break;
			}
			else if(s.top()<(2*b)){
				arr[0]++;
			}
			else{
				arr[1]++;
				if(arr[1]>=2){
					for(int k=0; k<num-j; k++) s.pop();
					cout << "NO" << endl;
					t=true;
					break;
				}
				l=s.top();
			}
			s.pop();
		}
		if(t) continue;
		if(arr[1]==0){
			if(arr[0]%2==1) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}
		if(arr[0]%2==0){
			if(l>=a&&l<=a+2*b-2) cout << "YES" << endl;
			else if(l>=3*a&&l<=a+4*b-2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else{
			if(l>=2*a&&l<=a+3*b-2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}