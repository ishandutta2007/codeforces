//  228

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define f first
#define s second
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
#define pb push_back

int lcm(int a, int b) 
{ 
    return ((a * b)/ __gcd(a, b)); 
} 

bool prime(int x)
{
  if (x < 2) return false;
  for(int i=2; i<= sqrt(x); i++) {
    if ((x%i) == 0) return false;
  }
  return true;
}

void solve()
{
	fast;
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }
    int i,flag=1;
    for(i=0;i<n;i++){
    	if(v[i]!=i+1)
		{
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<"0 0";return;
	}
	int x=v[i];
	reverse(v.begin()+i,v.end()-(n-v[i]));
	if(is_sorted(all(v))){
		cout<<i+1<<" "<<x;
		return;
	}
	cout<<"0 0";
}

int main() 
{
	fast;
	int t;
	t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}