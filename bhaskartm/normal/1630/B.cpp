#include<bits/stdc++.h>
using namespace std;
 
int main() {
 
    int tc;
    cin >> tc;
    while( tc-- ){
 
        int n, k;
        cin >> n >> k;
 
        vector<int> a(n), sorted_a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            sorted_a[i] = a[i];
        }
 
        sort(sorted_a.begin(),sorted_a.end());
 
        int req_sum = ( n + k + 1 ) / 2;
 
        pair<int,pair<int,int>> ans = { n + 1 , { -1 , -1 } };
 
        for(int i=0; i+req_sum-1<n; i++)
            ans = min( ans , { sorted_a[i+req_sum-1] - sorted_a[i] , { sorted_a[i] , sorted_a[i+req_sum-1] } } );
 
        cout << ans.second.first << ' ' << ans.second.second << '\n';
 
        int subarrays_found = 0, curr_sum = 0;
        int last_uncovered = 1;
 
        for(int i=0; i<n; i++){
 
            if( a[i] >= ans.second.first && a[i] <= ans.second.second ) curr_sum ++;
                else curr_sum --;
 
            if( curr_sum > 0 && subarrays_found + 1 < k ){
 
                cout << last_uncovered << ' ' << ( i + 1 ) << '\n';
                last_uncovered = i + 2;
 
                subarrays_found ++;
                curr_sum = 0;
            }
        }
 
        subarrays_found ++;
        cout << last_uncovered << ' ' << n << '\n';
 
    }
 
    return 0;
}