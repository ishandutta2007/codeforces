#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
Int x1, y1, x2, y2, a, b, c, n, res;
Int aa(Int x){
	if(x > 0)return 1;
	else return -1;
}
int main(){
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >> b >> c;
		if(aa(a*x1+b*y1+c) * aa(a*x2 +b*y2+c) < 0)res++;
	}
	cout << res << endl;
	return 0;
}