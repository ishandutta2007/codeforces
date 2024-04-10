#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
        sort(arr,arr+n);
        vector<int>v(n,0);
        for(int i = 0 ; i < n/2 ; i++)
        v[2*i] = arr[i];
        if(n%2 == 1)
        v[n-1] = arr[(n/2)+1];
        for(int i = 0 ; i < n/2 ; i++)
        v[2*i+1] = arr[i+(n/2)];
        int count = 0;
        // for(auto x : v)
        // cout << x << " ";
        // cout << endl;
        for(int i = 0 ; i < n ; i++)
        {
            if(i%2 == 1)
            {
                if(v[i] > v[i-1] && v[i] > v[(i+1)%n])
                count++;
            }
            else
            {
                if(v[i] < v[(i+n-1)%n] && v[i] < v[(i+1)%n])
                count++;
            }
        }
        if(count == n)
        {
            cout << "YES" << endl;
            for(auto x : v)
            cout << x << " ";
            cout << endl;
        }
        else
        cout << "NO" << endl;
    }
}