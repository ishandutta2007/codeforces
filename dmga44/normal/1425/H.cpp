#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int A, B, C, D;
    	cin >> A >> B >> C >> D;

    	int val = (A+B)&1;

    	if(val)
    	{
    		if(A || D)cout << "Ya ";
    		else cout << "Tidak ";
    		if(B || C)cout << "Ya ";
    		else cout << "Tidak ";
    		cout << "Tidak ";
    		cout << "Tidak ";
    		cout << '\n';
    	}
    	else
    	{
    		cout << "Tidak ";
    		cout << "Tidak ";
    		if(B || C)cout << "Ya ";
    		else cout << "Tidak ";
    		if(A || D)cout << "Ya ";
    		else cout << "Tidak ";
    		cout << '\n';
    	}
    }

    return 0;
}