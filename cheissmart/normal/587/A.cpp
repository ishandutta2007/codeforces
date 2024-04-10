#include <iostream>

using namespace std;

const int N = 1e6 + 5487;
int a[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0,w;i<n;i++)
		cin >> w,a[w]++;
	int ans=0;
	for(int i=0;i<N-1;i++)
		a[i+1] += a[i] >> 1, ans+=a[i]&1;
	cout << ans << endl;
}