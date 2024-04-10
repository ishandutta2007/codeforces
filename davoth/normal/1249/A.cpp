#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a,a+n);
        int sol=1;
        for(int i=0; i<n-1; i++){
            if(a[i]+1==a[i+1]){
                sol++;
                break;
            }
        }
        cout << sol << '\n';
    }
	return 0;
}