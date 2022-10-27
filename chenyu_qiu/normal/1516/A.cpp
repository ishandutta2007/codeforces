#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n, k;
        cin>> n>>k;
        vector <int> a(n);
        for(auto &i : a) cin >> i;
        for (int i = 0; k && i+1 < n; i++)
        {
            while(k&&a[i]) a[i]--, a.back()++, k--;
 
        }
        for(auto &i : a) cout << i <<" ";
        cout<<endl;
    }
 
}