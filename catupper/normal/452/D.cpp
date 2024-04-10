#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
	int k1, k2, k3, n1, n2, n3, t1, t2, t3;
	cin >> k1 >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	k2 = k3 = 0;
	queue<int> q1, q2, q3;
	int res = 0;
	while(k1 || k2 || k3 || !q1.empty() || !q2.empty() || !q3.empty()){
		while(!q1.empty() && q1.front() == res){
			q1.pop();
			k2++;
		}
		while(k1 && q1.size() < n1){
			k1--;
			q1.push(res + t1);
		}		
		while(!q2.empty() && q2.front() == res){
			q2.pop();
			k3++;
		}
		while(k2 && q2.size() < n2){
			k2--;
			q2.push(res + t2);
		}
		
		while(!q3.empty() && q3.front() == res){
			q3.pop();
		}
		while(k3 && q3.size() < n3){
			k3--;
			q3.push(res + t3);
		}
		res++;
	}
	cout << res - 1 << endl;
}