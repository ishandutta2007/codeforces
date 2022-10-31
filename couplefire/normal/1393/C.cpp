#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
{
	int n , ans = 0 , arr[100001] = {} , temp;
	cin >> n;
        for(int i = 0 ; i < n ; i++)
		cin >> temp , arr[temp]++;
	for(auto i : arr)
		ans = max(i,ans);
        for(auto i : arr)
		if(i==ans)
			n--;
        ans--;
        cout << n/ans-1 << endl;
}
}