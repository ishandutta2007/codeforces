#include <bits/stdc++.h>
using namespace std;
int n;
int a[(int)5e5+1];
bool check(int k){
    int l=0,r=n-k;
    for(int i=1; i<=k; i++){
        if(a[l]*2<=a[r]){
            l++;
            r++;
        }else return false;
    }
    return true;
}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    int l=0,r=n/2+1;
    while(r-l>1){
        int m=(r+l)/2;
        if(check(m)){
            l=m;
        }else r=m;
    }
    cout << n-(r)+1;
	return 0;
}