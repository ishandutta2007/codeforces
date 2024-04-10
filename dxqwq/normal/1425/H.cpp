#include <bits/stdc++.h>
using namespace std;

//Start
typedef long long ll;
typedef double db;
#define mp(a,b) make_pair((a),(b))
#define x first
#define y second
#define be(a) (a).begin()
#define en(a) (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define R(i,a,b) for(int i=(a),I=(b);i<I;i++)
#define L(i,a,b) for(int i=(b)-1,I=(a)-1;i>I;i--)
const int iinf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

//Data
int a,b,c,d;

//Main
void Main(){
	cin>>a>>b>>c>>d;
	if((a+b)&1){
		if(b+c==0) cout<<"Ya Tidak Tidak Tidak\n";
		else if(a+d==0) cout<<"Tidak Ya Tidak Tidak\n";
		else cout<<"Ya Ya Tidak Tidak\n";
	} else {
		if(b+c==0) cout<<"Tidak Tidak Tidak Ya\n";
		else if(a+d==0) cout<<"Tidak Tidak Ya Tidak\n";
		else cout<<"Tidak Tidak Ya Ya\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int tan; cin>>tan;
	while(tan--) Main();
	
	return 0;
}