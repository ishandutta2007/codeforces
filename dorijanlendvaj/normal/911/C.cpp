#include <bits/stdc++.h>

using namespace std;

int h[11];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>h[0]>>h[1]>>h[2];
	sort(h,h+3);
	if (h[0]==1 || (h[0]==2 && h[1]==2) || (h[0]==3 && h[1]==3 && h[2]==3) || (h[0]==2 && h[1]==4 && h[2]==4)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}