#include<iostream>
#include<algorithm>

using namespace std;

int yet0, yet1, done0, done1, now0, now1;
char c;
int n;
int tyet0, tyet1, tdone0, tdone1, tnow0, tnow1;
int main(){
	cin >> n;
	
	for(int i = 0;i < n;i++){
		cin >> c;    
		tyet0 = yet0;
		tyet1 = yet1;
		tdone0 = done0;
		tdone1 = done1;
		tnow0 = now0;
		tnow1 = now1;
		if(c == '0'){
			tyet0 = max(yet0, yet1 + 1);
			tdone0 = max(done0, done1 + 1);
			tdone0 = max(tdone0, now1 + 1);
			tnow1 = max(now1, now0 + 1);
			tnow1 = max(tnow1, yet0 + 1);
		}
		else{
			tyet1 = max(yet1, yet0 + 1);
			tdone1 = max(done1, done0 + 1);
			tdone1 = max(tdone1, now0 + 1);
			tnow0 = max(now0, now1 + 1);
			tnow0 = max(tnow0, yet1 + 1);
		}
		yet0 = tyet0;
		yet1 = tyet1;
		done0 = tdone0;
		done1 = tdone1;
		now0 = tnow0;
		now1 = tnow1;
	}	
	int res = 0;
	res = max(res, yet0);
	res = max(res, yet1);
	res = max(res, now0);
	res = max(res, now1);
	res = max(res, done0);
	res = max(res, done1);
	cout << res << endl;
	return 0;
}