#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

#define X first
#define Y second
#define rep(i,a,f) for(int i = a;i < f;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<string, string> PS;
typedef vector<PS> VPS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

int main(){
	string a = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char d;
	cin>>d;
	int k;
	if(d == 'R') k = -1;
	else k = 1;
	
	string c;
	cin>>c;
	for(int i = 0;i < (int)c.size();++i){
		for(int j = 0;j < (int)a.size();++j){
			if(c[i] == a[j]){
				cout<<a[j+k];
				break;
			}
		}
	}
	cout<<endl;
}