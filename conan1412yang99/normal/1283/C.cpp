
/*
	
    ||||      |||   ||\\  ||   ||||   |||||  ||
    ||  ||   |||||  || \\ ||    ||    ||||   ||
    ||||    ||   || ||  \\||   ||||   |||||  ||||||

	daniel071292

*/

#include <bits/stdc++.h>

using namespace std;

int a[200005], geted[200005];

int main() 
{
	int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int i = 1; i <= n; i++)
    	geted[a[i]] = 1;
    vector<int> give, toget;
    for(int i = 1; i <= n; i++)
    	if(a[i] == 0)
    		give.push_back(i);
    for(int i = 1; i <= n; i++)
    	if(geted[i] == 0)
    		toget.push_back(i);
    for(int i = 0; i < give.size(); i++)
    	if(give[i] == toget[i])
        	swap(toget[i], toget[(i+1)%give.size()]);
    for(int i = 0; i < give.size(); i++)
    	a[give[i]] = toget[i];
    for(int i = 1; i <= n; i++)
    	cout << a[i] << " ";
}