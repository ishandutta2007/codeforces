

    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long n,k;
        cin >> n >> k;
        long long a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        if(n==1){
            cout << a[0]+k;
            return 0;
        }
        for(int i=1; i<=n/2; i++){
            if(a[n/2+i]-a[n/2+i-1]>k/i){
                cout << a[n/2+i-1]+k/i;
                return 0;
            }else{
                k-=(a[n/2+i]-a[n/2+i-1])*i;
            }
        }
        cout << a[n-1]+k/(n/2+1);
        return 0;
    }