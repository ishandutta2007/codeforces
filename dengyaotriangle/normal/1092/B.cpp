#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=105;

int n;
int a[maxn];
int h[maxn];
int ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) h[a[i]]++;
	for(int i=1;i<=102;i++){
		if(h[i]%2){
			h[i+1]++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}