#include<fstream>
#include<string>

using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;	cin >> t;
	while (t--){
		int n;	cin >> n;
		if (n % 2)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}